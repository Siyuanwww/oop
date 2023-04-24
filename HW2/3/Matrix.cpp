#include <iostream>
#include "Matrix.h"

Matrix::Matrix() {}
Matrix::Matrix(int _row, int _col) : row(_row), col(_col) {
    elem = new int*[row];
    for (int i = 0; i < row; i++) {
        elem[i] = new int[col];
        for (int j = 0; j < col; j++) {
            elem[i][j] = 0;
        }
    }
}
Matrix::~Matrix() {
    // delete[] elem;
    // for (int i = 0; i < row; i++) {
    //     delete[] elem[i];
    // }
}
Matrix Matrix::operator+(const Matrix &b) {
    Matrix c(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            c[i][j] = elem[i][j] + b[i][j];
        }
    }
    return c;
}
Matrix Matrix::operator-(const Matrix &b) {
    Matrix c(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            c[i][j] = elem[i][j] - b[i][j];
        }
    }
    return c;
}
Matrix Matrix::operator*(const int k) {
    Matrix c(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            c[i][j] = elem[i][j] * k;
        }
    }
    return c;
}
Matrix Matrix::operator*(const Matrix &b) {
    Matrix c(row, b.col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < b.col; k++) {
                c[i][k] += elem[i][j] * b[j][k];
            }
        }
    }
    return c;
}
Matrix transpose(const Matrix &b) {
    Matrix c(b.col, b.row);
    for (int i = 0; i < b.row; i++) {
        for (int j = 0; j < b.col; j++) {
            c[j][i] = b[i][j];
        }
    }
    return c;
}
int* Matrix::operator[](int x) const {
    return elem[x];
}
int* Matrix::operator[](int x) {
    return elem[x];
}
std::ostream& operator<<(std::ostream &os, const Matrix &a) {
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            os << a[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}
std::istream& operator>>(std::istream &is, Matrix &a) {
    int r, c;
    is >> r >> c;
    a = Matrix(r, c);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            is >> a[i][j];
        }
    }
    return is;
}