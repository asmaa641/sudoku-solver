// jumanas matrix
// Nadine: I changed a lot haha sorry

#include "Matrix.h"
#include <cstdlib>
#include <sstream>
#include <stdexcept> // CHANGED: needed for runtime_error
#include <ctime>     // CHANGED: needed for srand/time
#include <iostream>
#include <string>

using namespace std;

// helper: block index 0..8
static inline int blockIndex(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

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

Matrix& Matrix::operator=(const Matrix & x){ //Nadine: changed it bc of an error
    if (this == &x) return *this;

    // CHANGED: free old memory to avoid leaks (was missing before)
    for (int i = 0; i < rows; ++i) delete [] matrix[i];
    delete [] matrix;

    // copy sizes
    rows = x.rows;
    cols = x.cols;

    // allocate and deep-copy
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) matrix[i][j] = x.matrix[i][j];
    }
    return *this;
}

Matrix Matrix::reader(string s){
    // FIXED: previous implementation mixed index loops and stringstream extraction.
    // CHANGED: now reads tokens correctly and validates the whole board before returning (hopefully lol).
    std::stringstream ss(s);
    Matrix m;
    std::string token;
    int row = 0, col = 0;
    while (ss >> token) {
        if (row >= 9) break;
        int val = std::stoi(token);
        if (val < 0 || val > 9) throw std::runtime_error("Invalid token");
        m.setCell(row, col, val);
        ++col;
        if (col == 9) { col = 0; ++row; }
    }
    // validate non-zero entries don't conflict
    for (int r=0;r<9;++r) {
        for (int c=0;c<9;++c) {
            if (m.getCell(r,c)!=0) {
                int v = m.getCell(r,c);
                m.setCell(r,c,0); // temporarily clear for validation
                if (!m.isValid(r,c,v)) {
                    // CHANGED: provide an error message
                    std::string msg = "Invalid input: conflict at (" + std::to_string(r) + "," + std::to_string(c) + ") value " + std::to_string(v);
                    throw std::runtime_error(msg);
                }
                m.setCell(r,c,v); // restore
            }
        }
    }
    return m; // FIXED: previously missing return
}



// CHANGED: generatePuzzle now mutates *this (so calling puzzle.generatePuzzle(2) actually fills puzzle)
// and it checks isValid BEFORE placing a value. Uses rand()%9.
Matrix Matrix::generatePuzzle(int dif) {
    // clear this board first
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int clues = 5;
    if (dif == 1) clues = 25;
    else if (dif == 2) clues = 15;
    else clues = 5;

    int placed = 0;
    int attemptsOverall = 0;
    const int MAX_OVERALL = 10000; // safety cap

    while (placed < clues && attemptsOverall < MAX_OVERALL) {
        ++attemptsOverall;
        int r = std::rand() % 9; // 0..8  (FIXED: was rand()%8)
        int c = std::rand() % 9;
        if (getCell(r, c) != 0) continue; // already filled, skip

        int v = 1 + (std::rand() % 9); // 1..9
        if (isValid(r, c, v)) {
            setCell(r, c, v);
            ++placed;
            // optional debug:
            // cout << "Placed " << v << " at (" << r << "," << c << ")\n";
        }
    }

    if (attemptsOverall >= MAX_OVERALL) {
        cout << "generatePuzzle: reached max attempts; placed " << placed << " clues\n";
    }

    return *this; // CHANGED: return this object so caller's puzzle is updated
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

// FIXED: correct loop conditions (previously used > which never iterated)
bool Matrix::isValid(int row, int col, int val){
    if (row < 0 || row >= 9 || col < 0 || col >= 9) return false;
    if (val < 1 || val > 9) return false;

    int cur = getCell(row, col); //check if theres an existing value
    if (cur != 0 && cur != val) return false; // assumes that cur = 0 means empty box

    //row check
    for(int j = 0; j < 9; j++){
        if ( j != col && getCell(row, j) == val) return false;
    }

    //col check
    for(int i = 0; i < 9; i++){
        if(i != row && getCell(i, col) == val) return false;
    }

    //3x3 grid check
    int r0 = (row/3) *3;
    int c0 = (col/3) * 3;
    for(int i = r0; i < r0+3; i++){
        for(int j = c0; j < c0+3; j++){
             if((i != row || j != col) && getCell(i,j) == val) return false;
        }
    }
    return true;
}

bool Matrix::isSolved() { //Nadine: Added to check if the sudoku is solved
    //if there are no empty cell, solved
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(getCell(i,j) == 0) return false;
        }
    }
    return true;
}