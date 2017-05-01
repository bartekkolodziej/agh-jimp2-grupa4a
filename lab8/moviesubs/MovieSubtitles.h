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

    class SubRipSubtitles : public MovieSubtitles {
    public:
        SubRipSubtitles() : MovieSubtitles() {};

        ~SubRipSubtitles(){};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);
        void ConvertTimeToCorrectFormat(int delay, int time_second, int time_milisecond, std::stringstream *out);

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() : MovieSubtitles() {};

        ~MicroDvdSubtitles(){};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);
        void IfNegative(int delay, int framerate);
        void IfEndEarlierThanStart(std::stringstream *in);

    };

    class MovieSubtitlesError : public std::runtime_error{
    public:
        MovieSubtitlesError(std::string error_message) : std::runtime_error(error_message){};

        virtual ~MovieSubtitlesError(){};
    };


    class NegativeFrameAfterShift : public  MovieSubtitlesError{
    public:
        NegativeFrameAfterShift() : MovieSubtitlesError("Negative frame after shift"){};
        ~NegativeFrameAfterShift(){};
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesError{
    public:
        SubtitleEndBeforeStart(const int &line) :  MovieSubtitlesError("Subtitles end before start"){};
        ~SubtitleEndBeforeStart(){};
        int LineAt() const{};
        int line_;
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesError{
    public:
        InvalidSubtitleLineFormat() :  MovieSubtitlesError("Invalid subtitle line format"){};
        ~InvalidSubtitleLineFormat(){};
    };

    class MissingTimeSpecification : public MovieSubtitlesError{
    public:
        MissingTimeSpecification() :  MovieSubtitlesError("Missing time specification"){};
        ~MissingTimeSpecification(){};
    };

    class OutOfOrderFrames : public MovieSubtitlesError{
    public:
        OutOfOrderFrames() :  MovieSubtitlesError("Out of order frames"){};
        ~OutOfOrderFrames(){};
    };



}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
