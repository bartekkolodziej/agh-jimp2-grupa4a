
// Created by bartek on 17.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>

#include <vector>
#include <cmath>

namespace tinyurl{
    struct TinyUrlCodec {
        std::vector<std::string> LongUrls;
        std::array<char, 6> state;
    };
    unsigned long int ToDecimal(std::array<char, 6> digit);
    std::array<char, 6> ConvertToHash(unsigned long int digit);
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);


}

#endif //JIMP_EXERCISES_TINYURL_H
