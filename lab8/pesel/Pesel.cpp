//
// Created by kolobart on 25.04.17.
//

#include "Pesel.h"

namespace academia {
    Pesel::Pesel(const char *pesel_) {
        if (validatePESEL(pesel_) == false) {
            throw WrongNumbers(pesel_);
        } else this->pesel_ = pesel_;
    }

    bool InvalidPeselChecksum();
    bool InvalidPeselLength();
    bool InvalidPeselCharacter();
    bool AcademiaDataValidationError();

    Pesel::~Pesel() {
    }

    AcademiaDataValidationError::AcademiaDataValidationError(std::string error_message){
        this->error_message=error_message;
    }

}