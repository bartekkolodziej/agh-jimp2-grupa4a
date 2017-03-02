//
// Created by bartek on 02.03.17.
//

#include "DoubleBasePalindromes.h"

using namespace std;
bool is_palindrome(string str){
    for(int i=0; i<str.length()/2; i++){
        if(str.at(i) == str.at(str.length()-i-1)) continue;
        else return false;
    }
    return true;
}

string to_binary(int number){
    string binary;
    int i = 0;
    while(number>0)
    {
        binary = binary + to_string(number%2);
        number = int(number/2);
        i++;
    }
    return binary;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    int sum = 0;
    for(int i=0; i < max_vaule_exculsive; i++){
        if( is_palindrome(to_string(i)) == 1 && is_palindrome(to_binary(i)) == 1) sum += i;
    }
    return sum;
}
