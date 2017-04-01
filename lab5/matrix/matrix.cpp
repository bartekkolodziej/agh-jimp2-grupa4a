//
// Created by bartosz on 01.04.17.
//

#include "matrix.h"

Matrix::Matrix(int rows, int cols) {
    this->cols=cols;
    this->rows=rows;
    this->matrix=new std::complex<double>[rows][cols];
}

Matrix::Matrix(const char *char_matrix) {
    int rows=0, cols=0, i=0;
    while(true){
        if(char_matrix[i]==";") {
            rows++;
            i++;
        }
        else if(char_matrix[i]=="]") break;
            else if(char_matrix[i]==" " or char_matrix[i]=="[")i++;
                else {  std::string tmp="";
                    while(char_matrix[i]!=" "){
                        tmp+=char_matrix[i];
                        i++;
                        }
                    this->matrix[rows][cols]=std::complex<double>(tmp);
                    if (rows==0) cols++;
                }
    }
    this->rows=rows;
    this->cols=cols;
}

Matrix::Matrix(const Matrix &m) {
    this->matrix=new std::complex<double>[m.rows][m.cols];
    for(int row=0;row<=m.rows;row++)
        for(int col=0;col<=m.cols;col++){
            this->matrix[row][col]=m.matrix[row][col];
        }

}
Matrix::Matrix add(const Matrix &m){
    if(this->rows !=m.rows or this->cols!=m.cols) return 1;
    Matrix new_matrix=Matrix(this->rows, this->cols);
    for(int row=0;row<=m.rows;row++)
        for(int col=0;col<=m.cols;col++){
            new_matrix[row][col]=m.matrix[row][col]+this->matrix[col][row];
        }
    return new_matrix;
}

Matrix::Matrix substract(const Matrix &m) {
    if (this->rows != m.rows or this->cols != m.cols) return 1;
    Matrix new_matrix = Matrix(this->rows, this->cols);
    for (int row = 0; row <= m.rows; row++)
        for (int col = 0; col <= m.cols; col++) {
            new_matrix[row][col] = this->matrix[col][row]-m.matrix[row][col];
        }
    return new_matrix;
}

Matrix::Matrix scalarMultiplication(std::complex<double> scalar) {
    Matrix new_matrix = Matrix(this->rows, this->cols);
    for (int row = 0; row <= m.rows; row++)
        for (int col = 0; col <= m.cols; col++) {
            new_matrix[row][col] = this->matrix[col][row]*scalar;
        }
    return new_matrix;
}

Matrix::Matrix scalarDivision(std::complex<double> scalar) {
    if (scalar==0)return 1;
    Matrix new_matrix = Matrix(this->rows, this->cols);
    for (int row = 0; row <= m.rows; row++)
        for (int col = 0; col <= m.cols; col++) {
            new_matrix[row][col] = this->matrix[col][row]/scalar;
        }
    return new_matrix;
}

Matrix::Matrix matrixMultiplication(const Matrix &m) {
    if(this->cols != m.rows) return 1;
    Matrix new_matrix = Matrix(this->rows, this->cols);
    for (int row = 0; row <= m.rows; row++)
        for (int col = 0; col <= m.cols; col++){
            std::complex<double> tmp=0;
            for(int i=0;i<=m.rows;i++) tmp=tmp+this->matrix[row][i]*m.matrix[i][col];
            new_matrix[row][col] = tmp;
        }
    return new_matrix;
}

Matrix::Matrix exponentiation(int number) {
    Matrix new_matrix = Matrix(this);
    for (int i=0;i<number;i++)new_matrix=new_matrix.matrixMultiplication(this)
    return new_matrix;
}


