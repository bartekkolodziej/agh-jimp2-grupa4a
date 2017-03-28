//
// Created by bartosz on 26.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <regex>
#include <unordered_map>

namespace nets {
    class View {
    public:
    View(std::string text);
    ~View();
    std::string Render(const std::unordered_map<std::string, std::string> &model) const;
        std::string raw_text;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
