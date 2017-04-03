//
// Created by bartosz on 01.04.17.
//

#include "Matrix.h"
namespace algebra {

    Matrix::Matrix() {}

    Matrix::~Matrix() {}; // not complete

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

        for (int row = 0; row <= m.rows; row++)
            for (int col = 0; col <= m.cols; col++) {
                this->matrix[row][col] = m.matrix[row][col];
            }
    }

    Matrix Matrix::Add(const Matrix &m) const {
        if (this->rows != m.rows or this->cols != m.cols) {
            std::cout << "Incorrect dimensions" << std::endl;
            return *this;
        }
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row <= this->rows; row++)
            for (int col = 0; col <= this->cols; col++) {
                new_matrix.matrix[row][col] = m.matrix[row][col] + this->matrix[col][row];
            }
        return new_matrix;
    }

    Matrix Matrix::substract(const Matrix &m) {
        if (this->rows != m.rows or this->cols != m.cols) {
            std::cout << "Incorrect dimensions" << std::endl;
            return *this;
        }
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row <= this->rows; row++)
            for (int col = 0; col <= this->cols; col++) {
                new_matrix.matrix[row][col] = this->matrix[col][row] - m.matrix[row][col];
            }
        return new_matrix;
    }

    Matrix Matrix::scalarMultiplication(std::complex<double> scalar) {
        Matrix new_matrix{this->rows, this->cols};
        for (int row = 0; row <= this->rows; row++)
            for (int col = 0; col <= this->cols; col++) {
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
        for (int row = 0; row <= this->rows; row++)
            for (int col = 0; col <= this->cols; col++) {
                new_matrix.matrix[row][col] = this->matrix[col][row] / scalar;
            }
        return new_matrix;
    }

    Matrix Matrix::Mul(const Matrix &m) {
        if (this->cols != m.rows) {
            std::cout << "Incorrect dimensions";
            return *this;
        }
        Matrix new_matrix{this->rows, m.cols};
        for (int row = 0; row <= m.rows; row++)
            for (int col = 0; col <= m.cols; col++) {
                std::complex<double> tmp;
                tmp.real(0);
                tmp.imag(0);
                for (int i = 0; i <= m.rows; i++) tmp = tmp + this->matrix[row][i] * m.matrix[i][col];
                new_matrix.matrix[row][col] = tmp;
            }
        return new_matrix;
    }

    Matrix Matrix::exponentiation(int number) {
        if (number==0){
            Matrix new_matrix=Matrix(this->rows,this->cols);
            for(int row=0;row<this->rows;row++){
                for(int col=0;col<this->cols;col++){
                    if(row==col){
                        new_matrix.matrix[row][col]=1;
                    }
                    else new_matrix.matrix[row][col]=0;
                }
            }
            return new_matrix;
        }
        if(number<0){
            std::cout << "Please, type number equal to 0 or greater than 0.";
            return *this;
        }
        Matrix new_matrix{*this};
        for (int i = 0; i < number; i++) new_matrix = new_matrix.Mul(*this);
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

    void Matrix::Print() const {
        std::cout<<"[";
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->cols; col++) {
                std::cout << real(this->matrix[row][col])<<"i"<<imag(this->matrix[row][col]);
                if(row==this->rows-1){
                    std::cout<<"; ";
                }
                else std::cout<<", ";
            }
        }
    }
}