//
// Created by bartek on 01.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs{

    void MicroDvdSubtitles::IfNegative(int delay, int framerate) {
        if(delay < 0 || framerate < 0) throw NegativeFrameAfterShift();
    }
    void MicroDvdSubtitles::IfInvalidArgument(std::stringstream *in){
        if((*in).str() == "") throw std::invalid_argument("elo");
    }

    void MicroDvdSubtitles::IfEndEarlierThanStart(std::stringstream *in){
        std::string text, frame_start, frame_end;
        text = (*in).str();
        int line = 0;

        for(int i = 0; i < text.length(); i++){
            if(text[i] == '\n') line++;
            if(text[i] == '{' && isdigit(text[i+1])){
                frame_start = "";
                frame_end = "";
                i++;
                while(text[i] != '}') {
                    frame_start += text[i];
                    i++;
                }
                i += 2;
                while(text[i] != '}'){
                    frame_end += text[i];
                    i++;
                }
            }
        }
        if(frame_end < frame_start) throw SubtitleEndBeforeStart(line, in);
    }

    void MicroDvdSubtitles::IfIncompleteLine(std::stringstream *in) {

        }


    std::string ReturnLineWithError(int line, std::stringstream *in){
        std::string text, text_to_return ="";
        text = (*in).str();
        int current_line = 1;

        for(int i = 0; i < text.length(); i++){
            if(text[i] == '\n') current_line++;
            if(current_line == line){
                i++;
                while(text[i] != '\n'){
                    text_to_return += text[i];
                    i++;
                }
            }
        }
        return text_to_return;
    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
        IfIncompleteLine(in);
        IfInvalidArgument(in);
        IfNegative(delay, framerate);
        IfEndEarlierThanStart(in);


        std::string text, frame;
        text = (*in).str();
        for(int i = 0; i < text.length(); i++){
            if(text[i] == '{' && isdigit(text[i+1])){
                frame = "";
                i++;
                while(text[i] != '}') {
                    frame += text[i];
                    i++;
                }
                *out << '{' + std::to_string(atoi(frame.c_str()) + (delay*framerate)/1000) + '}';
            }
            else *out << text[i];
        }
        if(text[text.length() - 1] != '\n') *out << '\n';
    }


    void SubRipSubtitles::ConvertTimeToCorrectFormat(int delay, int time_seconds, int time_miliseconds, std::stringstream *out){
        *out << ':';
        if(time_miliseconds + delay < 1000) {
            if(time_seconds < 10){
                if(time_miliseconds > 100) *out <<'0' + std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds+delay);
                if(time_miliseconds < 100) *out <<'0' + std::to_string(time_seconds) + ",0"+ std::to_string(time_miliseconds+delay);
                if(time_miliseconds < 10) *out <<'0' + std::to_string(time_seconds) + ",00"+ std::to_string(time_miliseconds+delay);
            }
            if(time_seconds > 10){
                if(time_miliseconds > 100) *out <<std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds+delay);
                if(time_miliseconds < 100) *out <<std::to_string(time_seconds) + ",0"+ std::to_string(time_miliseconds+delay);
                if(time_miliseconds < 10) *out <<std::to_string(time_seconds) + ",00"+ std::to_string(time_miliseconds+delay);
            }
        }
        else{
            time_seconds += (time_miliseconds + delay) / 1000;
            time_miliseconds = (time_miliseconds + delay) % 1000;
            if(time_seconds < 10){
                if(time_miliseconds > 100) *out <<'0' + std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds);
                if(time_miliseconds < 100) *out <<'0' + std::to_string(time_seconds) + ",0"+ std::to_string(time_miliseconds);
                if(time_miliseconds < 10) *out <<'0' + std::to_string(time_seconds) + ",00"+ std::to_string(time_miliseconds);
            }
            if(time_seconds > 10){
                if(time_miliseconds > 100) *out <<std::to_string(time_seconds) + ','+ std::to_string(time_miliseconds);
                if(time_miliseconds < 100) *out <<std::to_string(time_seconds) + ",0"+ std::to_string(time_miliseconds);
                if(time_miliseconds < 10) *out <<std::to_string(time_seconds) + ",00"+ std::to_string(time_miliseconds);
            }
        }
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
                time_seconds = (text[i+1] - 48) * 10 + text[i+2] - 48;
                i += 3;
                time_miliseconds = (text[i+1] - 48) * 100 + (text[i+2]-48) * 10 + text[i+3] - 48;
                i += 3;

                ConvertTimeToCorrectFormat(delay, time_seconds, time_miliseconds, out);
            }
            else *out << text[i];
        }
    }


}