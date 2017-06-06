//
// Created by kolobart on 06.06.17.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H

#include <string>
#include <iostream>
#include <stdexcept>

std::string to_roman(unsigned int value);
class NegativeNumber : public std::runtime_error {
public:
    NegativeNumber() : std::runtime_error("Negative number"){};
};

class InvalidInput : public std::runtime_error {
public:
    InvalidInput() : std::runtime_error("Invalid Input"){};

};

class OutOfRange : public std::runtime_error {
public:
    OutOfRange() : std::runtime_error("Out Of Range"){};

};

void IfNegative(int value);
void IfInvalidInput(std::string value);
void IfOutOfRange(int value);



int value(char roman);

int to_arabic(const std::string& input);

#endif //JIMP_EXERCISES_ARABICROMAN_H
