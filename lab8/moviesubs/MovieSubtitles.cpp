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

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
        std::string text, frame;
        text = (*in).str();
        int line=0;
        if(framerate<=0) throw WrongFramerateException(framerate);
        for(int i = 0; i < text.length(); i++){
            if(text[i] ==  '\\' and text[i + 1] == 'n') line++;
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
                    frame = "";
                    i++;
                    if(text[i] != '{') throw InvalidSubtitleLineFormat();
                    int start = atoi(frame.c_str());
                    if (start<0) throw NegativeFrameAfterShift();
                    while(text[i] != '}') {
                        if(IsNotNumber(text[i]))throw InvalidSubtitleLineFormat();
                        frame += text[i];
                        i++;
                    }
                    int end = atoi(frame.c_str());
                    if (end<0) throw NegativeFrameAfterShift();
                    if (start<end) throw SubtitleEndBeforeStart(line);
                    *out << '{' + std::to_string(start + (delay*framerate)/1000) + '}'+'{' + std::to_string(end + (delay*framerate)/1000) + '}';
            }
            else *out << text[i];
        }
    }

    int SubtitleEndBeforeStart::LineAt() const{
        return line_;
    }



}