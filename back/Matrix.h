//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_MATRIX_H
#define VMTRIANGLE_MATRIX_H
#include "Vector.h"
// опишем нужные операции, умножение матрицы на матрицу, вектор на вектор, равенство, транспонирование.

class Matrix {
    
public:
    double values[3][3];//3x3 наша матрица с типом double, int тут ни к черту
    Matrix& operator=(Matrix A);
    Matrix operator*(Matrix A);
    Vector operator*(Vector A);
    Matrix transpose();
};

#endif //VMTRIANGLE_MATRIX_H
