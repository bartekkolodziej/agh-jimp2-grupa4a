//
// Created by kolobart on 25.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>
#include <iostream>

namespace academia {
    class Pesel {
    public:
        Pesel(const char *pesel_);
        ~Pesel();
        bool validatePESEL(const char *pesel_);
        bool InvalidPeselChecksum();
        bool InvalidPeselLength();
        bool InvalidPeselCharacter();
        bool AcademiaDataValidationError();

        const char *pesel_;
    };

    class AcademiaDataValidationError{
    public:
        AcademiaDataValidationError(std::string error_message);
        virtual  ~AcademiaDataValidationError();
        std::string error_message;
    };

    class WrongNumbers : public AcademiaDataValidationError {
    public:
        WrongNumbers(const char *pesel_) : AcademiaDataValidationError{"Wrong dimensions of matrix"}, pesel_{pesel_} {}

        Pesel pesel_;
    };
}

#endif //JIMP_EXERCISES_PESEL_H
