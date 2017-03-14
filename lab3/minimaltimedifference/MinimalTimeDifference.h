//
// Created by bartek on 14.03.17.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>


namespace minimaltimedifference{
    unsigned int ToMinutes(std::string time_HH_MM);
    unsigned int MinimalTimeDifference(std::vector<std::string> times);
    int Difference(int a, int b);
    int FindMinDifference(const std::vector<int> differences);
}



#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
