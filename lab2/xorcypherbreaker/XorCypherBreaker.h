//
// Created by bartek on 12.03.17.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary);
int compare(vector<string> dictionary, vector<char> message);
vector<char> xor_crypt(vector<char> message, string key);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
