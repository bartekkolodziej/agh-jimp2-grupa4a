//
// Created by bartek on 01.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <stdexcept>


namespace moviesubs {

    class MovieSubtitles {
    public:
        MovieSubtitles(){};

        ~MovieSubtitles(){};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out){};

    };

    std::string ReturnLineWithError(int line, std::stringstream *in);

    class SubRipSubtitles : public MovieSubtitles {
    public:
        SubRipSubtitles() : MovieSubtitles() {};

        ~SubRipSubtitles(){};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() : MovieSubtitles() {};

        ~MicroDvdSubtitles(){};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);

    };


    class MovieSubtitlesError : public std::runtime_error{
    public:
        MovieSubtitlesError(std::string error_message) : std::runtime_error(error_message){};

        virtual ~MovieSubtitlesError(){};
    };


    class WrongFramerateException : public std::invalid_argument {
    public:
        WrongFramerateException(const int &framerate) : invalid_argument{"Framerate must be higher than 0."}, framerate_{framerate}{};
        int framerate_;
        ~WrongFramerateException(){};

    };

    class NegativeFrameAfterShift : public  MovieSubtitlesError{
    public:
        NegativeFrameAfterShift() : MovieSubtitlesError{"Negative frame after shift"}{};
        ~NegativeFrameAfterShift(){};
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesError{
    public:
        SubtitleEndBeforeStart(const std::pair<int,int> &line, std::stringstream *in) :
                line_{line.first},
                MovieSubtitlesError("At line " + std::to_string(line.first) + ": " + ReturnLineWithError(line.second, in) ) {};
        ~SubtitleEndBeforeStart(){};
        int LineAt() const;
        int line_;
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesError{
    public:
        InvalidSubtitleLineFormat() :  MovieSubtitlesError("Invalid subtitle line format"){};
        ~InvalidSubtitleLineFormat(){};
    };

}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
