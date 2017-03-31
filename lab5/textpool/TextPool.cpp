//
// Created by bartek on 31.03.17.
//

#include "TextPool.h"

namespace pool{

    TextPool::TextPool(){
        text_ = "";
    };

    TextPool::TextPool(TextPool &&text_pool){
        int i = text_pool.elements_.size();
        text_pool.elements_[i] = nullptr;
        std::swap(elements_[i],text_pool.elements_[i]);
    }

    TextPool & TextPool::operator=(TextPool &&text_pool){
        int i = text_pool.elements_.size();
        if (this == &text_pool) {
            return text_pool;
        }
        text_ = nullptr;
        std::swap(elements_[i],text_pool.elements_[i]);
    }

    TextPool::TextPool(const std::initializer_list<std::string> &elements){
        for(auto x: elements) elements_.push_back(x);
    }
    std::experimental::string_view TextPool::Intern(const std::string &str){
        std::experimental::string_view str_tmp;
        for(auto x: elements_){
            if(x == str){
                str_tmp = str;
                return str_tmp;
            }
            else {
                elements_.push_back(str);
                return str;
            }
        }
    }

}