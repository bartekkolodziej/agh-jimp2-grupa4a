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
        //std::regex pattern ("{{(?<subexpression>\\w)\\k<subexpression>}}");
        //std::string rendered_text=std::regex_replace(raw_text, pattern, model.at("&{subexpression}"));
        std::string rendered_text = raw_text;
        for (auto v : model){
            size_t index = 0;
            std::string tmp="{{"+v.first+"}}";
            while (true) {
                index = rendered_text.find(tmp, index);
                if (index == std::string::npos) break;
                rendered_text.replace(index, tmp.length(), v.second);
                index += tmp.length();
            }
        }
        //std::regex pattern ("({{\\w}})");
        //std::string text;
        //text=std::regex_replace(rendered_text,pattern,"");
        return rendered_text;
    }
}
