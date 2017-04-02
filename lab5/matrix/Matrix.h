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

namespace algebra {

    class Matrix {
    public:
        Matrix();

        Matrix(int rows, int cols);

        Matrix(const Matrix &m);

        Matrix(const char *char_matrix);

        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);

        Matrix Add(const Matrix &m) const;

        Matrix substract(const Matrix &m);

        Matrix scalarMultiplication(std::complex<double> scalar);

        Matrix scalarDivision(std::complex<double> scalar);

        Matrix Mul(const Matrix &m);

        Matrix matrixDivision(Matrix &m);

        Matrix exponentiation(int number);

        Matrix invertion();

        void Print() const;

        std::pair<size_t, size_t> Size() const; // what is it for?
        ~Matrix();

    private:
        int rows;
        int cols;
        std::complex<double> **matrix;
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
