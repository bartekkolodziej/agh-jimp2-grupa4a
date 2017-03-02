//
// Created by bartek on 02.03.17.
//

#include "Palindrome.h"

using namespace std;
bool is_palindrome(string str){
    for(int i=0; i<str.length()/2; i++){
        if(str.at(i) == str.at(str.length()-i-1)) continue;
        else return false;
    }
    return true;
}