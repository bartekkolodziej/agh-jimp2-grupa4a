//
// Created by bartek on 01.05.17.
//

#include "MovieSubtitles.h"


namespace moviesubs{

    bool IsNotNumber(const char &x ){
        std::string dictionary = "1234567890";
        for(auto i: dictionary){
            if (i == x) return false;
        }
        return true;
    }

    std::string ReturnLineWithError(int i, std::stringstream *in) {
        std::string text, text_to_return = "";
        text = (*in).str();
        i++;
        while(text[i] != '\n'){
            text_to_return += text[i];
            i++;
        }
        return text_to_return;
    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
        std::string text, frame;
        text = (*in).str();
        if(delay < 0) throw NegativeFrameAfterShift();
        std::pair<int,int> line={1,0};
        if(framerate<=0) throw WrongFramerateException(framerate);
        for(int i = 0; i < text.length(); i++){
            if(text[i] ==  '\n') {
                line.first++;
                line.second=i;
            }
            if(text[i] == '}') throw InvalidSubtitleLineFormat();
            if(text[i] == '{'){
                frame = "";
                i++;
                if(text[i] == '}') throw InvalidSubtitleLineFormat();
                while(text[i] != '}') {
                    if(IsNotNumber(text[i]))throw InvalidSubtitleLineFormat();
                    frame += text[i];
                    i++;
                }
                int start = atoi(frame.c_str());
                if (start<0) throw NegativeFrameAfterShift();
                frame = "";
                i++;
                if(text[i] != '{') throw InvalidSubtitleLineFormat();
                i++;
                if(text[i] == '}') throw InvalidSubtitleLineFormat();
                while(text[i] != '}') {
                    if(IsNotNumber(text[i]))throw InvalidSubtitleLineFormat();
                    frame += text[i];
                    i++;
                }
                int end = atoi(frame.c_str());
                if (end<0) throw NegativeFrameAfterShift();
                if (start>=end) throw SubtitleEndBeforeStart(line,in);
                *out << '{' + std::to_string(start + (delay*framerate)/1000) + '}'+'{' + std::to_string(end + (delay*framerate)/1000) + '}';
                if (text[i+1]=='{') {
                    i++;
                    *out << '{';
                    i++;
                    while(text[i]!='}') {
                        *out <<text[i];
                        i++;
                    }
                    *out <<'}';
                }
            }
            else *out << text[i];
        }
        if(text[text.length() - 1] != '\n') *out << '\n';
    }

    int SubtitleEndBeforeStart::LineAt() const{
        return line_;
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
        std::string text;
        int time_seconds, time_miliseconds;
        text = (*in).str();

        for(int i = 0; i < text.length(); i++){
            if((text[i] == '\n' && isdigit(text[i+1])) || (text[i] == '-' && text[i+1] == '-')){
                time_seconds = 0;
                time_miliseconds = 0;
                while(text[i+3] != ',') {
                    *out << text[i];
                    i++;
                }
                *out << ':';
                time_seconds = (text[i+1] - 48) * 10 + text[i+2] - 48;
                i += 3;
                time_miliseconds = (text[i+1] - 48) * 100 + (text[i+2]-48) * 10 + text[i+3] - 48;
                i += 3;

                if(time_miliseconds + delay < 1000) {
                    if(time_seconds < 10){
                        *out << '0' + std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds+delay);
                    }else if(time_miliseconds < 100){
                        *out <<std::to_string(time_seconds) + ",0"+ std::to_string(time_miliseconds+delay);
                    }else if(time_miliseconds < 10){
                        *out <<std::to_string(time_seconds) + ",00"+ std::to_string(time_miliseconds+delay);
                    }else *out <<std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds+delay);
                }

                else{
                    time_seconds += (time_miliseconds + delay) / 1000;
                    time_miliseconds = (time_miliseconds + delay) % 1000;
                    if(time_seconds < 10){
                        *out << '0' + std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds);
                    }else if(time_miliseconds < 100){
                        *out <<std::to_string(time_seconds) + ",0"+ std::to_string(time_miliseconds);
                    }else if(time_miliseconds < 10){
                        *out <<std::to_string(time_seconds) + ",00"+ std::to_string(time_miliseconds);
                    }else *out <<std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds);
                }
            }
            else *out << text[i];
        }
    }




}