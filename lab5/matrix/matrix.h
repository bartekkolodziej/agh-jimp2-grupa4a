//
// Created by bartosz on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

class Matrix{
    public:
        Matrix();
        Matrix(int rows, int cols);
        Matrix(const Matrix &m);
        Matrix(const char* char_matrix);
        Matrix add(const Matrix &m);
        ~Matrix();
    private:
        int rows;
        int cols;
        std::complex<double> matrix[rows][cols];
};

#endif //JIMP_EXERCISES_MATRIX_H
