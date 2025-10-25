//
// Created by Arwa Hassan on 23/10/2025.
//

#ifndef SUDOKU_SOLVER_MATRIX_H
#define SUDOKU_SOLVER_MATRIX_H

#include <iostream>

class Matrix {
int rows;
int cols;
int** matrix;

public:
    Matrix();
    Matrix(const Matrix & x);
    Matrix& operator=(const Matrix & x);
    ~Matrix ();
    int getCell(int, int);
    void setCell(int, int, int);
    bool isEmpty(int, int);
    void print();

};


#endif //SUDOKU_SOLVER_MATRIX_H
