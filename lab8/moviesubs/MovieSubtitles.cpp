//
// Created by bartek on 01.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
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