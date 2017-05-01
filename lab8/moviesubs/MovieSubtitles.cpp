//
// Created by bartek on 01.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
        std::string text, frame;
        text = (*in).str();

        for(int i = 0; i < text.length(); i++){
            if(text[i] == '{'){
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
    }



}