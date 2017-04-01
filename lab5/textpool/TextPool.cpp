//
// Created by bartek on 31.03.17.
//

#include "TextPool.h"

namespace pool{

    TextPool::TextPool(){
        elements_.push_back("");
        count_ = 0;
    }

    TextPool::TextPool( TextPool&& text_pool )
            : elements_( std::move( text_pool.elements_ ) )
    {
        count_ = text_pool.count_;
        text_pool.count_ = 0;
    }

    TextPool & TextPool::operator=(TextPool &&text_pool){
        if (this == &text_pool) {
            return text_pool;
        }
        for(int i=0; i<text_pool.count_; i ++) {
            std::swap(elements_[i], text_pool.elements_[i]);
        }
    }

    TextPool::TextPool(const std::initializer_list<std::string> &elements){
        count_ = 0;
        for(std::experimental::string_view x: elements){
            for(std::experimental::string_view y: elements_){
                if(y == x){
                    goto here;
                }
            }
            count_++;
            elements_.push_back(x);
            here:
            count_ += 0;
        }
    }
    std::experimental::string_view TextPool::Intern(const std::string &str){
        for(std::experimental::string_view x: elements_){
            if(x == str){
                return x;
            }
        }
        elements_.push_back(std::experimental::string_view(str));
        count_++;
        return str;
    }

    size_t TextPool::StoredStringCount() const{
        return count_;
    }

    TextPool::~TextPool(){}


}