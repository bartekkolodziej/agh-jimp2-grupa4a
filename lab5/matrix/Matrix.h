//
// Created by bartosz on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <string>
#include <initializer_list>
#include <vector>
#include <cstring>

using namespace std::complex_literals;

namespace algebra {

    class Matrix {
    public:
        Matrix();

        Matrix(int rows, int cols);

        Matrix(const Matrix &m);

        Matrix(const char *char_matrix);

        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);

        Matrix Add(const Matrix &m) const;

        Matrix Sub(const Matrix &m);

        Matrix Mul(const Matrix &m);

        Matrix Pow(int number);

        std::string Print() const;

        std::pair<size_t, size_t> Size() const; // what is it for?

        ~Matrix();

    private:
        int rows;
        int cols;
        std::complex<double> **matrix;
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
