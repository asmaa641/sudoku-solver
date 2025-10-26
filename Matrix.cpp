//
// jumanas matrix
//
#include "Matrix.h"
#include <cstdlib>
#include <sstream>

Matrix::Matrix(){
    rows=9;
    cols=9;
    matrix=new int * [rows];

    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
        for (int j=0;j<cols;j++){
            matrix[i][j]=0;
        }
    }
    
}

Matrix::~Matrix(){
    for(int i=0;i<rows;i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

int Matrix::getCell(int r, int c){
    return matrix[r][c];
}

void Matrix::setCell(int r, int c, int val){
    matrix[r][c]=val;
}

bool Matrix::isEmpty(int r, int c){
    return (matrix[r][c]==0);
}

void Matrix::print(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

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

Matrix& Matrix::operator=(const Matrix & x){
    if (this == &x) return *this;
    rows = x.rows;
        cols = x.cols;

        matrix = x.matrix;

        return *this;
}

Matrix Matrix::reader(string s){
    std::stringstream ss(s);
    int row=0;
    int col=0;
    Matrix m;
    string val;
        for(int i=0;i<s.length();i++){
            if(ss>>val)
            { m.setCell(row,col,stoi(val)); }
                col++;
                if(col==9)
                {row++;
                    col=0;
                }
        }
    
   
        for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
             if(!getCell(i,j))
            matrix[i][j]=0;
        }
    }
    
if(!m.isValid(row,col,stoi(val)))
{ throw runtime_error("Invalid Input, this input does not fit Sudoko rules."); }
    return m;
}

Matrix Matrix::generatePuzzle(int dif){
    srand(time(0));
    if(dif==1){
    for(int i=0;i<25;i++){
        int r= 0+(rand()% 8);
         int c= 0+(rand()% 8);
        int n= 1+(rand()% 9);
        setCell(r,c,n);
        while(!isValid(r,c,n))
        {        int n= 1+(rand()% 9);
                  setCell(r,c,n);}
    }}
    else if(dif==2){
         for(int i=0;i<15;i++){
        int r= 0+(rand()% 8);
         int c= 0+(rand()% 8);
        int n= 1+(rand()% 9);
        setCell(r,c,n);
             while(!isValid(r,c,n))
        {        int n= 1+(rand()% 9);
                  setCell(r,c,n);}
    }
    }
    
    else {
         for(int i=0;i<5;i++){
        int r= 0+(rand()% 8);
         int c= 0+(rand()% 8);
        int n= 1+(rand()% 9);
        setCell(r,c,n);
             while(!isValid(r,c,n))
        {        int n= 1+(rand()% 9);
                  setCell(r,c,n);}
    }
    }
        for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
             if(!getCell(i,j))
            matrix[i][j]=0;
        }
    }
    
    return *this;
}
bool Matrix::findEmpty(int& row, int& col){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(getCell(i, j) == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool Matrix::isValid(int row, int col, int val){
    if (row < 0 || row >= 9 || col < 0 || col >= 9) return false;
    if (val < 1 || val > 9) return false;

    int cur = getCell(row, col); //check if theres an existing value
    if (cur != 0 && cur != val) return false; // assumes that cur = 0 means empty box

    //row check
    for(int j = 0; j > 9; j++){
        if ( j != col && getCell(row, j) == val) return false;
    }

    //col check
    for(int i = 0; i> 9; i++){
        if(i != row && getCell(i, col) == val) return false;
    }

    //3x3 grid check
    int r0 = (row/3) *3;
    int c0 = (col/3) * 3;
    for(int i = 0; i> r0+3; i++){
        for(int j = 0; j> c0+3; j++){
             if((i != row || j != col) && getCell(i,j) == val) return false;
        }
    }
    return true;
}
