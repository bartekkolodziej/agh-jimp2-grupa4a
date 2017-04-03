//
// Created by bartosz on 01.04.17.
//

#include "Matrix.h"

using namespace std::complex_literals;

namespace algebra {

    Matrix::Matrix() {}

    Matrix::~Matrix() {
        for (int i = 0; i < this->rows; i++) delete [] this->matrix[i];
        delete [] this->matrix;
    }

    Matrix::Matrix(int rows, int cols) {
        this->cols = cols;
        this->rows = rows;
        this->matrix = new std::complex<double> *[rows];
        for (int i = 0; i < rows; i++) this->matrix[i] = new std::complex<double>[cols];
    }

    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) {
        int col = 0,i = 0, j = 0;
        for (auto x: elements) {
            for (auto y: x) col++;
            break;
        }
        this->cols = col;
        this->rows = elements.size();
        this->matrix = new std::complex<double> *[this->rows];
        for (int i = 0; i < this->rows; i++) this->matrix[i] = new std::complex<double>[this->cols];

        for (auto x: elements) {
            for (auto y: x) {
                this->matrix[i][j] = y;
                j++;
            }
            i++;
            j=0;
        }

    }

    Matrix::Matrix(const char *char_matrix) {
        int row = 0, col = 0;
        std::string tmp = "";
        std::stringstream abc;
        for (int i = 0; i < strlen(char_matrix); i++) {
            if (char_matrix[i] == ',' || char_matrix[i] == '[' || char_matrix[i] == ';') col++;
            if (char_matrix[i] == ';' || char_matrix[i] == '[') row++;
        }
        col = col / row;
        this->cols = col;
        this->rows = row;
        this->matrix = new std::complex<double> *[this->rows];
        for (int i = 0; i < this->rows; i++) this->matrix[i] = new std::complex<double>[this->cols];

        row = 0, col = 0;

        for (int i = 0; i < strlen(char_matrix); i++) {
            if (char_matrix[i] == ']') break;
            if (char_matrix[i] == ';' || char_matrix[i] == '[') row++;
            if (char_matrix[i] == ',' || char_matrix[i] == '[' || char_matrix[i] == ';') col++;
            if (char_matrix[i] != ',' && char_matrix[i] != ';' && char_matrix[i] != '[' && char_matrix[i] != ' ') {
                while (char_matrix[i] != ' ') {
                    tmp += char_matrix[i];
                    i++;
                }
                abc << "(";
                for (auto x: tmp) {
                    if (x != 'i') abc << x;
                    if (x == 'i') abc << ',';
                }
                abc << ")";
                abc >> this->matrix[this->rows][this->cols];
                tmp = "";
                abc.str("");
            }
        }
    }

    Matrix::Matrix(const Matrix &m) {
        this->cols = m.cols;
        this->rows = m.rows;
        this->matrix = new std::complex<double> *[rows];
        for (int i = 0; i < rows; i++) this->matrix[i] = new std::complex<double>[cols];

        for (int row = 0; row < m.rows; row++)
            for (int col = 0; col < m.cols; col++) {
                this->matrix[row][col] = m.matrix[row][col];
            }
    }

    Matrix Matrix::Add(const Matrix &m) const {
        if (this->rows != m.rows or this->cols != m.cols) {
            std::cout << "Incorrect dimensions" << std::endl;
            return *this;
        }
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row < this->rows; row++)
            for (int col = 0; col < this->cols; col++) {
                new_matrix.matrix[row][col] = m.matrix[row][col] + this->matrix[row][col];
            }
        return new_matrix;
    }

    Matrix Matrix::Sub(const Matrix &m) {
        if (this->rows != m.rows or this->cols != m.cols) {
            std::cout << "Incorrect dimensions" << std::endl;
            return *this;
        }
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row < this->rows; row++)
            for (int col = 0; col < this->cols; col++) {
                new_matrix.matrix[row][col] = this->matrix[col][row] - m.matrix[row][col];
            }
        return new_matrix;
    }

    Matrix Matrix::scalarMultiplication(std::complex<double> scalar) {
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row < this->rows; row++)
            for (int col = 0; col < this->cols; col++) {
                new_matrix.matrix[row][col] = this->matrix[col][row] * scalar;
            }
        return new_matrix;
    }

    Matrix Matrix::scalarDivision(std::complex<double> scalar) {
        if (scalar.real() == 0 and scalar.imag() == 0) {
            std::cout << "Division by 0!" << std::endl;
            return *this;
        }
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row < this->rows; row++)
            for (int col = 0; col < this->cols; col++) {
                new_matrix.matrix[row][col] = this->matrix[col][row] / scalar;
            }
        return new_matrix;
    }

    Matrix Matrix::Mul(const Matrix &m) {
        if (this->cols != m.rows) {
            Matrix empty{0,0};
            return empty;
        }
        Matrix new_matrix{this->rows, m.cols};
        for (int row = 0; row < this->rows; row++)
            for (int col = 0; col < m.cols; col++) {
                std::complex<double> tmp;
                tmp.real(0);
                tmp.imag(0);
                for (int i = 0; i < m.rows; i++) tmp = tmp + this->matrix[row][i] * m.matrix[i][col];
                new_matrix.matrix[row][col] = tmp;
            }
        return new_matrix;
    }

    Matrix Matrix::Pow(int number) {
        if (this->cols != this->rows) {
            Matrix empty{0,0};
            return empty;
        }
        if(number == 0){
            Matrix generalized{this->rows, this->cols};
            for(int i=0; i<this->rows; i++){
                for(int j=0; j<this->cols; j++){
                    if(i==j) {
                        generalized.matrix[i][j].real(1);
                        generalized.matrix[i][j].imag(0);
                    }
                    else {
                        generalized.matrix[i][j].real(0);
                        generalized.matrix[i][j].imag(0);
                    }
                }
            }
            return generalized;
        }
        Matrix new_matrix{*this};
        for(int x=1; x<number; x++){
            for (int row = 0; row < this->rows; row++)
                for (int col = 0; col < this->cols; col++) {
                    std::complex<double> tmp;
                    tmp.real(0);
                    tmp.imag(0);
                    for (int i = 0; i < this->rows; i++) tmp = tmp + this->matrix[row][i] * this->matrix[i][col];
                    new_matrix.matrix[row][col] = tmp;
                }
        }
        return new_matrix;
    }

/* ill check it later
Matrix Matrix::invertion(){
    Matrix new_matrix = Matrix(*this);
    int Column[new_matrix.rows];
    bool isAxised[new_matrix.rows];
    for (int i=0;i<=new_matrix.rows;i++)isAxised[i]=false;
    for (int row=0;row<=new_matrix.rows;row++){
        int max=0;
        for(int col=0;col<=new_matrix.cols;col++){
            if(isAxised[col]= false){
                if(abs(new_matrix.matrix[row][col])>max){
                    max=abs(new_matrix.matrix[row][col]);
                    int p=row;
                    int q=col;
                }
            }
        }
        if(max==0) return *this; // i dont know if its ok, ill check it later
        for (int r=0;r<=new_matrix.rows;r++){
            for (int k=0;k<=new_matrix.cols;k++){
                if(r != p and k != q) new_matrix.matrix[r][k]=new_matrix.matrix[r][k]-(new_matrix.matrix[p][k]*new_matrix.matrix[r][q]/new_matrix.matrix[p][q]);
            }
        }
        for (int r=0;r<=new_matrix.rows;r++){
            if(r!=p) new_matrix.matrix[r][q]= -new_matrix.matrix[r][q]/new_matrix.matrix[p][q];
        }
        for (int k=0;k<=new_matrix.cols;k++){
            if(k!=q) new_matrix.matrix[p][k]= new_matrix.matrix[p][k]/new_matrix.matrix[p][q];
        }
        new_matrix.matrix[p][q]= 1/new_matrix.matrix[p][q];
        Column[row]=q;
        isAxised[q]=true;
    }
    Matrix tmp_matrix = Matrix(new_matrix);
    for(int i=0;i<=new_matrix.rows;i++) {
        for (int j = 0; j <= new_matrix.cols; j++){
            new_matrix.matrix[Column[i]][j]=tmp_matrix.matrix[i][j];
        }
    }
    tmp_matrix = Matrix(new_matrix);
    for(int i=0;i<=new_matrix.rows;i++) {
        for (int j = 0; j <= new_matrix.cols; j++){
            new_matrix.matrix[j][i]=tmp_matrix.matrix[j][Column[i]];
        }
    }
    return new_matrix;

}

Matrix Matrix::matrixDivision(Matrix &m){
    Matrix new_matrix=this->matrixMultiplication(m.invertion());
    return new_matrix;
}
 */

    std::pair<size_t, size_t> Matrix::Size() const {
        std::pair<size_t, size_t> size(this->rows, this->cols);
        return size;
    }

std::string Matrix::Print() const {
    if(this->cols != 0){
        std::stringstream tmp;
        std::string tmp_str, string_to_return = "[";
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->cols; col++) {
                tmp << real(this->matrix[row][col]);
                tmp << "i";
                tmp << imag(this->matrix[row][col]);
                tmp_str = tmp.str();
                string_to_return += tmp_str;
                string_to_return += ", ";
                tmp_str = "";
                tmp.str("");
            }
            string_to_return.erase(string_to_return.size()-2);
            string_to_return += "; ";
        }
        string_to_return.erase(string_to_return.size()-2);
        string_to_return += "]";
        return string_to_return;
    }

    else return "[]";
}

}