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
        std::regex pattern {R"(({{(?<subexpression>\w+)}}))"};
        std::string rendered_text=std::regex_replace(raw_text, pattern, model.at("&{subexpression}"));
        return rendered_text;
    }
}
