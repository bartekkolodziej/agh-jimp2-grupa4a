//
// Created by bartek on 02.03.17.
//
#include "ReverseString.h"


using namespace std;

string reverse(string str){
    if (str.length() == 1 || str.length() == 0) {
        return str;
    }else{
        return reverse(str.substr(1,str.length())) + str.at(0);
    }
}
