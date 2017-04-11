//
// Created by kolobart on 11.04.17.
//

#include "ArrayFill.h"

namespace arrays {

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return this->offset_ + index * this->step_;
    }

    int SquaredFill::Value(int index) const{
        return this->a_ * index * index + this->b_;
    }

    int RandomFill::Value(int index) const{

        return (*p2)(*p1);
    }


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }


    IncrementalFill::IncrementalFill(int offset, int step) {
        this->offset_ = offset;
        this->step_ = step;
    }

    SquaredFill::SquaredFill(int a, int b){
        this->a_ = a;
        this->b_ = b;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> p1, std::unique_ptr<std::uniform_int_distribution<int>> p2){
        this->p1 = std::move(p1);
        this->p2 = std::move(p2);
    }
}