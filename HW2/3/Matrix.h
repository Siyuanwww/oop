#include <iostream>
class Matrix {
private:
    int** elem;
    int row, col;
    
public:
    Matrix();
    Matrix(int _row, int _col);
    ~Matrix();

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const int);
    Matrix operator*(const Matrix&);
    friend Matrix transpose(const Matrix&);
    int* operator[](int) const;
    int* operator[](int);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
};