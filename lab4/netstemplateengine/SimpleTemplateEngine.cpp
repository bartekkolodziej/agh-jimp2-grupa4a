//
// Created by bartosz on 26.03.17.
//

#include "SimpleTemplateEngine.h"

namespace nets{
    View::View(std::string text){
        raw_text=text;
    }
    View::~View(){}
    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{
        std::string new_text = "";
        std::string tmp = "";
        for(auto x: model) {
            for(int i=0; i < raw_text.size(); i++){
                if(raw_text[i] == '{' && raw_text[i+1] == '{' && raw_text[i+2] != '{'){
                    i += 2;
                    while(raw_text[i] != '}'){
                        tmp += raw_text[i];
                        i++;
                    }
                    if(raw_text[i+1] == '}'){
                        if(tmp == x.first) {
                            new_text += x.second;
                            i++;
                            tmp = "";
                        }
                        else {
                            tmp = "";
                            i++;
                        }
                    }
                    else {
                        new_text += "{{" + tmp + "}";
                        tmp = "";
                    }
                }
                else new_text += raw_text[i];
            }
        }
        return new_text;
    }

}

