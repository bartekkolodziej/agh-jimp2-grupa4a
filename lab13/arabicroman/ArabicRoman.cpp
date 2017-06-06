//
// Created by kolobart on 06.06.17.
//

#include "ArabicRoman.h"

std::string to_roman(unsigned int value){
    IfNegative(value);
    IfOutOfRange(value);
    struct romandata_t { unsigned int value; char const* numeral; };
    const struct romandata_t romandata[] =
            {
                    {1000, "M"}, {900, "CM"},
                    {500, "D"}, {400, "CD"},
                    {100, "C"}, { 90, "XC"},
                    { 50, "L"}, { 40, "XL"},
                    { 10, "X"}, { 9, "IX"},
                    { 5, "V"}, { 4, "IV"},
                    { 1, "I"},
                    { 0, NULL} // end marker
            };

    std::string result;
    for (const romandata_t* current = romandata; current->value > 0; ++current)
    {
        while (value >= current->value)
        {
            result += current->numeral;
            value -= current->value;
        }
    }
    return result;
}

void IfNegative(int value) {
    if(value < 0) throw NegativeNumber();
}

int value(char roman) {
    switch(roman)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
}

int to_arabic(const std::string &input) {
    IfInvalidInput(input);
    int sum=0; char prev='%';
    for(int i=(input.length()-1); i>=0; i--)
    {
        if(value(input[i])<sum && (input[i]!=prev))
        {       sum -= value(input[i]);
            prev = input[i];
        }
        else
        {
            sum += value(input[i]);
            prev = input[i];
        }
    }
    return sum;
}

void IfInvalidInput(std::string value) {
    for(auto x: value){
        switch(x)
        {
            case 'I': continue;
            case 'V': continue;
            case 'X': continue;
            case 'L': continue;
            case 'C': continue;
            case 'D': continue;
            case 'M': continue;
            default : throw InvalidInput();
        }
    }
}

void IfOutOfRange(int value) {
    if(value > 3999) throw OutOfRange();

}
