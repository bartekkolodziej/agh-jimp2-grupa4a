//
// Created by bartek on 01.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>


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

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() : MovieSubtitles() {};

        ~MicroDvdSubtitles(){};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);

    };

}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
