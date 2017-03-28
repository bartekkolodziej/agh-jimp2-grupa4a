//
// Created by bartek on 25.03.17.
//

#include "SimpleJson.h"



namespace nets{

    JsonValue::JsonValue(int x){
        x_ = x;
        value_type = 1;
    }
    JsonValue::JsonValue(double y){
        y_ = y;
        value_type = 2;
    }
    JsonValue::JsonValue(std::string str){
        str_ = str;
        value_type = 3;
    }
    JsonValue::JsonValue(bool z){
        z_ = z;
        value_type = 4;
    }
    JsonValue::JsonValue(std::vector<JsonValue> v){
        v_ = v;
        value_type = 5;
    }
    JsonValue::JsonValue(std::map<std::string, JsonValue> m){
        m_ = m;
        value_type = 6;
    }

    JsonValue::JsonValue(const char* c){
        c_ = c;
        value_type = 7;
    }
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        return std::experimental::make_optional(m_.at(name));
    }
    std::string JsonValue::ToString() const{
        switch(value_type){
            case 1:
                return std::to_string(x_);
            case 2: {
                std::ostringstream strs;
                strs << y_;
                std::string str_double = strs.str();
                return str_double;
            }
            case 3: {
                std::string new_str = "\"";
                for(int i = 0; i < str_.size(); i++){
                    if(str_[i] == '\"') new_str += "\\\"";
                        else {
                        if (str_[i] == '\\') new_str += "\\\\";
                        else new_str += str_[i];
                    }
                }
                new_str += "\"";
                return new_str;
            }
            case 4:
                return z_ ? "true" : "false";
            case 5: {
                std::string str_v = "[";
                for (int i = 0; i < v_.size() - 1; i++) {
                    str_v += v_[i].ToString() + ", ";
                }
                str_v += v_[v_.size() - 1].ToString() + "]";
                return str_v;
            }
            case 6:{
                std::string str_m = "{";
                for(auto x: m_) str_m += "\"" + x.first + "\"" + ": " + x.second.ToString();
                str_m += "}";
                return str_m;
            }
            case 7: {
                std::string new_str = "\"";
                for (int i = 0; i < strlen(c_); i++) {
                    if (c_[i] == '\"') new_str += "\\\"";
                    else {
                        if (c_[i] == '\\') new_str += "\\\\";
                        else new_str += c_[i];
                    }
                }
                new_str += "\"";
                return new_str;
            }
            default:
                return "error";
        }

    }
    JsonValue::~JsonValue(){}
}