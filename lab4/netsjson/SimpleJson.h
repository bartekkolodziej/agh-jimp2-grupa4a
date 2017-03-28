//
// Created by bartek on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>

namespace nets {
    class JsonValue {
    public:
        JsonValue();

        JsonValue(int x);

        JsonValue(double y);

        JsonValue(std::string str);

        JsonValue(bool z);

        JsonValue(std::vector<JsonValue> v);

        JsonValue(std::map<std::string, JsonValue> m);

        JsonValue(const char* c);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

        ~JsonValue();

        int x_;

        double y_;
        std::string str_;
        bool z_;
        std::vector<JsonValue> v_;
        std::map<std::string, JsonValue> m_;
        int value_type;
        const char * c_;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H