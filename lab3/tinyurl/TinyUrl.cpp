//
// Created by bartosz on 17.03.17.
//

#include "TinyUrl.h"
#include <vector>

namespace tinyurl {
    struct TinyUrlCodec;
    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> p = std::make_unique<TinyUrlCodec>();
        p->state = {'0', '0', '0', '0', '0', '0'};
        return p;
    }

    void NextHash(std::array<char, 6> *state){
        std::string dictionary="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        if ((*state)[5]=='z'){
            (*state)[5]='0';
            if ((*state)[4]=='z'){
                (*state)[4]='0';
                if ((*state)[3]=='z'){
                    (*state)[3]='0';
                    if ((*state)[2]=='z'){
                        (*state)[2]='0';
                        if ((*state)[1]=='z'){
                            (*state)[1]='0';
                            if ((*state)[0]!='z')
                            (*state)[0]=dictionary[dictionary.find((*state)[0])+1];
                        }
                        else (*state)[1]=dictionary[dictionary.find((*state)[1])+1];
                    }
                    else (*state)[2]=dictionary[dictionary.find((*state)[2])+1];
                }
                else (*state)[3]=dictionary[dictionary.find((*state)[3])+1];
            }
            else (*state)[4]=dictionary[dictionary.find((*state)[4])+1];
        }
        else (*state)[5]=dictionary[dictionary.find((*state)[5])+1];
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        NextHash(&(*codec)->state);
        (*codec)->tab.emplace_back(url);
        std::string short_url="";
        for (auto i:(*codec)->state){
            short_url=short_url+i;
        }
        return short_url;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        std::string dictionary="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int id=0;
        for(int i=0;i<=6;i++){
            id = 62*id + (int)(dictionary.find(hash[i]));
        }
        if(id<=codec->tab.size())return codec->tab[id];
        return"";
    }
}