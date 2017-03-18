//
// Created by bartek on 17.03.17.
//

#include "TinyUrl.h"

namespace tinyurl {

    unsigned long int ToDecimal(std::array<char, 6> digit){
        std::string alfabet = "0123456789ABCDEFGHIJKLMNOUPQRSTWXYZabcdefghijklmnoupqrstwxyz";
        unsigned long int sum = 0;
        int p = 0;
        for(int i = 5; i>=0; i--){
            for(int j = 0; j < 60; j++){
                if (digit[i] == alfabet[j]) {
                    sum = sum + j * pow(60,p);
                    p=p+1;
                }
            }
        }
        return sum;
    }


    std::array<char, 6> ConvertToHash(unsigned long int digit) {
        std::string alfabet = "0123456789ABCDEFGHIJKLMNOUPQRSTWXYZabcdefghijklmnoupqrstwxyz";
        std::array<char, 6> hash;
        int p = 5;
        while (digit > 0) {
            hash[p] = alfabet[digit % 60];
            digit = digit / 60;
            p = p - 1;
        }
        while (p >= 0) {
            hash[p] = '0';
            p = p - 1;
        }
        return hash;
    }

    struct TinyUrlCodec {
        std::vector<std::string> LongUrls;
        std::array<char, 6> state;
    };

    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> p = std::make_unique<TinyUrlCodec>();
        p->state = {'0', '0', '0', '0', '0', '0'};
        p->LongUrls.push_back("FirstURL");
        return p;
    }

    void NextHash(std::array<char, 6> *state) {
        std::string alfabet = "0123456789ABCDEFGHIJKLMNOUPQRSTWXYZabcdefghijklmnoupqrstwxyz";
        unsigned long int a = ToDecimal(*state);
        *state = ConvertToHash(a + 1);

    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string stringReturned = "";
        NextHash(&(*codec)->state);
        (*codec)->LongUrls.push_back(url);
        for(auto x: (*codec)->state) stringReturned += x;
        return stringReturned;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        std::array<char, 6> tabHash= {'0','0','0','0','0','0'};
        for(int i = 0; i < hash.length(); i++) tabHash[i] = hash[i];
        return codec->LongUrls[ToDecimal(tabHash)];
    }

}