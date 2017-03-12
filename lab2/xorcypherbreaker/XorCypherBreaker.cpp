//
// Created by bartek on 12.03.17.
//

#include "XorCypherBreaker.h"


vector<char> xor_crypt(vector<char> message, string key){
    vector<char> ascii_message;
    int xor_value;
    int i = 0;

    for(auto x: message){
        xor_value = int(x) ^ key[i];
        ascii_message.push_back(char(xor_value));
        i = (i+1) % 3;
    }

    return ascii_message;
}

int compare(vector<string> dictionary, vector<char> message){
    string single_word;
    int same_words = 0;
    for(auto x: message) {
        if(x != 32) single_word += x;
        if(x == 32) {
            for(auto a: dictionary){
                if(a == single_word) same_words++;
            }
            single_word = "";
        }
    }
    return same_words;
}

string XorCypherBreaker(const vector<char> &cryptogram,
                        int key_length,const vector<string> &dictionary){
    string key;
    vector<char> encrypted;
    for(int i = 97; i <= 122; i++) {
        for (int j = 97; j <= 122; j++) {
            for (int k = 97; k <= 122; k++) {
                key = "";
                key += char(i);
                key += char(j);
                key += char(k);
                encrypted = xor_crypt(cryptogram, key);
                if (compare(dictionary, encrypted) > 10) return key;
            }
        }
    }
    return "";
}