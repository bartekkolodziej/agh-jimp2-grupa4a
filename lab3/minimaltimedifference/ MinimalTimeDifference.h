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
using namespace std;



int Difference(int a, int b);
int FindMinDifference(vector<int> differences);
unsigned int ToMinutes(string time_HH_MM);
unsigned int MinimalTimeDifference(vector<string> times);

#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
