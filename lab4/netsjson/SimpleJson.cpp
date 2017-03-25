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
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{

    }
    std::string JsonValue::ToString() const{
      switch(value_type){
          case 1:
              return std::to_string(x_);
          case 2:
              return std::to_string(y_);
          case 3:
              return str_;
          case 4:
              return z_ ? "true" : "false";
          default:
              return "not finished yet";
      }

    }
    JsonValue::~JsonValue(){}
}