//
// Created by kolobart on 25.04.17.
//

#include "Pesel.h"


namespace academia {

    void Pesel::validatePESEL(const char *pesel){


    };

    Pesel::Pesel(const char *pesel) {
        validatePESEL(pesel);

        this->pesel = pesel;
    }



    Pesel::~Pesel() {};

    AcademiaDataValidationError::AcademiaDataValidationError(std::string error_message) : std::runtime_error(error_message){}

    InvalidPeselChecksum::InvalidPeselChecksum(std::string pesel, int computed_checksum) : AcademiaDataValidationError("Invalid Pesel("+pesel+") checksum: "+std::to_string(computed_checksum)){}

    InvalidPeselCharacter::InvalidPeselCharacter(std::string pesel) : AcademiaDataValidationError ("Invalid Pesel("+pesel+") character set"){}

    InvalidPeselLength::InvalidPeselLength(std::string pesel, int computed_checksum) : AcademiaDataValidationError("Invalid Pesel("+pesel+") length: "+std::to_string(computed_checksum)){}
}