//
// jumanas matrix
//

#include "Matrix.h"

Matrix:: Matrix () {
    rows=9;
    cols=9;
    matrix=new int * [rows];

    for (int i=0;i<rows; i++) {
        matrix[i]=new int[cols];
        }

    Matrix::~Matrix() {
        for (int i=0; i<rows; i++) {
            delete [] matrix[i];
            delete [] matrix;}
    }

    int Matrix:: getCell(int r, int c){
            return matrix[r][c];
            }

    void Matrix:: setCell(int r, int c, int val){
            matrix[r][c]=val;

            }

    bool Matrix:: isEmpty(int r, int c){
            return (matrix[r][c]==0);
            }

    void Matrix: :print(){
            for (int i=0; i‹rows; i++) {
            for (int j=0; j<cols;j++){
            cout<<matrixlillik" ";
            }}

            cout<<endl; }
}