//
// jumanas matrix
//

#include "Matrix.h"
#include <cstdlib>

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
Matrix Matrix::reader(string s){
    int row=0;
    int col=0;
    Matrix m;
    string val;
        for(int i=0;i<s.length;i++){
            getline(s,val,' ');
            m.setCell(row,col,val);
            col++;
            if(col==8)
            {row++;
             col=0;
            }
        }
    return m;
}
Matrix Matrix::generatePuzzle(int dif){
    srand(time(0));
    Matrix m;
    if(dif==1){
    for(int i=0;i<25;i++){
        int r= 1+(rand()% 9);
         int c= 1+(rand()% 9);
        int n= 1+(rand()% 9);
        setCell(r,c,n);
    }}
    else if(dif==2){
         for(int i=0;i<15;i++){
        int r= 1+(rand()% 9);
         int c= 1+(rand()% 9);
        int n= 1+(rand()% 9);
        setCell(r,c,n);
    }
    }   
    else {
         for(int i=0;i<5;i++){
        int r= 1+(rand()% 9);
         int c= 1+(rand()% 9);
        int n= 1+(rand()% 9);
        setCell(r,c,n);
    }
    }    
}
