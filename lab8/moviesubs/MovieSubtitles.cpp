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

    void MicroDvdSubtitles::IfIncompleteLine(std::stringstream *in) { // tutaj mozna bylo uzyc regexa, ale nie umiem
        std::string text;
        int brackets = 0;
        text = (*in).str();

        for(int i = 0; i < text.length(); i++) {
            if (brackets < 4) {
                if (text[i] == '{') {
                    if (!isdigit(text[i + 1])) throw InvalidSubtitleLineFormat();
                    brackets++;
                    i++;
                    while (text[i] != '}') {
                        if (!isdigit(text[i])) throw InvalidSubtitleLineFormat();
                        i++;
                    }
                }
                if (text[i] == '}') brackets++;
            }
                if (text[i] == '\n') {
                    if (brackets != 4) throw InvalidSubtitleLineFormat();
                    else brackets = 0;
                }

        }
    }


    std::string ReturnLineWithError(int line, std::stringstream *in){
        std::string text, text_to_return ="";
        text = (*in).str();
        int current_line = 1;

        for(int i = 0; i < text.length(); i++){
            if(text[i] == '\n' && text[i+1] == '{') current_line++;
            if(isdigit(text[i]) && text[i+1] == '\n' && isdigit(text[i+2]) && i != 0) {
                current_line++;
                i++;
            }
            if(current_line == line){
                i++;
                while(text[i] != '\n'){
                    text_to_return += text[i];
                    i++;
                }
                break;
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

    int SubRipSubtitles::ConvertTimeToMiliseconds(std::string time){
        int time_miliseconds = 0;
        std::string hours="", minutes="", seconds="", miliseconds="";
        hours += time[0];
        hours += time[1];

        minutes += time[3];
        minutes += time[4];

        seconds += time[6];
        seconds += time[7];

        miliseconds += time[9];
        miliseconds += time[10];
        miliseconds += time[11];

        time_miliseconds = atoi(hours.c_str())*3600000 + atoi(minutes.c_str())*60000 + atoi(seconds.c_str()) * 1000 + atoi(miliseconds.c_str());

        return time_miliseconds;
    }


    void SubRipSubtitles::IfNegative(int delay, int framerate){
        if(delay < 0 || framerate < 0) throw NegativeFrameAfterShift();
    }

    void SubRipSubtitles::IfEndEarlierThanStart(std::stringstream *in){
        std::string text, time_start, time_end;
        int line = 1;
        text = (*in).str();
        for(int i = 0; i < text.length(); i++){
            if(text[i] == '\n' && text[i+1] == '\n') line ++;
            if(text[i] == '\n' && isdigit(text[i+1]) && isdigit(text[i+2])){
                time_start = "";
                i++;
                while(text[i+1] != '-'){
                    time_start += text[i];
                    i++;
                }
            }
            if(text[i] == '-' && text[i+1] == '-' && text[i+2] == '>'){
                time_end = "";
                i += 4;
                while(text[i] != '\n'){
                    time_end += text[i];
                    i++;
                }
                if(ConvertTimeToMiliseconds(time_start) > ConvertTimeToMiliseconds(time_end)) throw SubtitleEndBeforeStart(line, in);
            }

        }
    }

    void SubRipSubtitles::IfInvalidArgument(std::stringstream *in){
        if((*in).str() == "") throw std::invalid_argument("elo");
    }

    void SubRipSubtitles::IfIncompleteLine(std::stringstream *in){ // tutaj tez monza bylo uzyc regexa
        std::string text;
        text = (*in).str();
        for(int i=0; i<text.length(); i++){
            if(isdigit(text[i]) && text[i+1] == '\n' && isdigit(text[i+2])){
                i += 2;
                while(text[i+2] != ',') {
                        if (!isdigit(text[i]) || !isdigit(text[i+1])) throw InvalidSubtitleLineFormat();
                        i += 3;
                    }
                if (!isdigit(text[i]) || !isdigit(text[i+1])) throw InvalidSubtitleLineFormat();
                i +=3;
                if (!isdigit(text[i]) || !isdigit(text[i+1]) || !isdigit(text[i+2])) throw InvalidSubtitleLineFormat();
                i += 3;
                if (text[i] != ' ' || text[i+1] != '-' || text[i+2] != '-' || text[i+3] != '>' || text[i+4] != ' ') throw InvalidSubtitleLineFormat();
                i += 5;
                while(text[i+2] != ',') {
                    if (!isdigit(text[i]) || !isdigit(text[i+1])) throw InvalidSubtitleLineFormat();
                    i += 3;
                }
                if (!isdigit(text[i]) || !isdigit(text[i+1])) throw InvalidSubtitleLineFormat();
                i +=3;
                if (!isdigit(text[i]) || !isdigit(text[i+1]) || !isdigit(text[i+2])) throw InvalidSubtitleLineFormat();

            }
            }
        }



    void SubRipSubtitles::IfFramesOutOfOrder(std::stringstream *in){
        std::string text;
        int current_line = 1;
        text = (*in).str();
        for(int i=0; i<text.length(); i++){
            if(i+5> text.length()) break;
            if(text[i] == '\n' && text[i+1] == '\n' && (text [i+2] - 48) != (current_line + 1)) throw OutOfOrderFrames();
            if(text[i] == '\n' && text[i+1] == '\n' && (text [i+2] - 48) == (current_line + 1)) current_line++;
        }
    }
    

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){
        IfInvalidArgument(in);
        IfIncompleteLine(in);
        IfFramesOutOfOrder(in);
        IfNegative(delay, framerate);
        IfEndEarlierThanStart(in);


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