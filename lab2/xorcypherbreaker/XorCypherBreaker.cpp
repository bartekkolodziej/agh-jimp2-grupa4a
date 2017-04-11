#include "XorCypherBreaker.h"

void keyGenerator(string key, int number, vector<string> *keyArray) {
    if (number==0) {
        (*keyArray).emplace_back(key);
    }
    for (int i=97;i<123;i++) keyGenerator(key+char(i),number-1 , keyArray);
}

vector<char> xor_crypt(vector<char> message, string key, int key_length){
    vector<char> ascii_message;
    int xor_value;
    int i = 0;

    for(auto x: message){
        xor_value = int(x) ^ key[i];
        ascii_message.push_back(char(xor_value));
        i = (i+1) % key_length;
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
    vector<char> encrypted;
    vector<string> keyArray;
    keyGenerator("",key_length, &keyArray);
    for(auto key : keyArray){
                encrypted = xor_crypt(cryptogram, key,key_length);
                if (compare(dictionary, encrypted) > 10) return key;
            }

    return "";
}