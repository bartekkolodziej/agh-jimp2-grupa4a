//
// Created by kolobart on 25.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace academia {

    class Pesel {
    public:
        Pesel(const char *pesel);

        ~Pesel();

        void validatePESEL(const char *pesel);

        const char *pesel;

    };


    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(std::string error_message);

        virtual ~AcademiaDataValidationError();
    };


    class WrongNumbers : public AcademiaDataValidationError {
    public:
        WrongNumbers(const char *&p) : AcademiaDataValidationError{"Wrong numbers"}, p_{p} {}

        Pesel p_;
    };


    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(std::string pesel, int computed_checksum);
        ~InvalidPeselChecksum(){};

    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string pesel, int computed_checksum);
        ~InvalidPeselLength(){};
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(std::string pesel);
        ~InvalidPeselCharacter(){};
    };


}


#endif //JIMP_EXERCISES_PESEL_H
