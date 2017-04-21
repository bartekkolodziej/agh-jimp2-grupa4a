//
// Created by kolobart on 11.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <vector>
#include <random>
#include <memory>


namespace arrays {


    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}

        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int offset = 0, int step = 1);

        virtual int Value(int index) const override;

    private:
        int offset_;
        int step_;

    };


    class SquaredFill : public ArrayFill{
    public:
        SquaredFill(int a = 1, int b = 0);

        virtual int Value(int index) const override;

    private:
        int a_, b_;
    };

    class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> p1, std::unique_ptr<std::uniform_int_distribution<int>> p2);

        virtual int Value(int index) const override;

    private:
        std::unique_ptr<std::default_random_engine> p1;
        std::unique_ptr<std::uniform_int_distribution<int>> p2;

    };

}

#endif //JIMP_EXERCISES_ARRAYFILL_H
