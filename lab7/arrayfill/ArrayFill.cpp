//
// Created by kolobart on 11.04.17.
//

#include "ArrayFill.h"
namespace arrays {
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return offset_ + index * step_;
    }
    int SquaredFill::Value(int index) const {
        return a_*index*index +b_;
    };

    int RandomFill::Value(int index) const {
        return (*b_)(*a_);
    };

    IncrementalFill::IncrementalFill(int offset, int step) {
        offset_ = offset;
        step_ = step;

    }
    SquaredFill::SquaredFill(int a , int b ){
        a_=a;
        b_=b;
    }
    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> a, std::unique_ptr<std::uniform_int_distribution<int>> b){
        a_=std::move(a);
        b_=std::move(b);
    }

}