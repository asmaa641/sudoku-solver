//
// jumanas matrix
//

#include "Matrix.h"

Matrix::Matrix () {
    rows=9;
    cols=9;
    matrix=new int * [rows];
    for (int i=0;i<rows; i++) {
        matrix[i]=new int[cols];
        }}
Matrix::Matrix(const Matrix & x){
    this->rows=x.rows;
    this->cols=x.cols;
    this->matrix = new int*[rows];  
    for (int i = 0; i < rows; i++) {
        this->matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] = x.matrix[i][j];
        }
    }
}
Matrix&::Matrix operator=(const Matrix & x){
    for (int i = 0; i < x.rows; i++) {
        for (int j = 0; j <x.cols; j++) {
            if(this->matrix[i][j] != x.matrix[i][j])
                return null;
        }
    }
    return *this;
}
    Matrix::~Matrix() {
        for (int i=0; i<rows; i++) {
            delete [] matrix[i];
            }
            delete [] matrix;}


    int Matrix:: getCell(int r, int c){
            return matrix[r][c];
            }

    void Matrix:: setCell(int r, int c, int val){
            matrix[r][c]=val;

            }

    bool Matrix:: isEmpty(int r, int c){
            return (matrix[r][c]==0);
            }

    void Matrix::print(){
            for (int i=0; i<rows; i++) {
            for (int j=0; j<cols;j++){
            std::cout<< matrix[i][j] << " ";
            }}

            std::cout<<std::endl; }
