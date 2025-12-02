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

Matrix::~Matrix(){
    for(int i=0;i<rows;i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

bool Matrix::fillSolutionBacktrack() {//this function will create the whole puzzple and then we can remove an element at a time depending on the difficulty level
    int r = -1, c = -1;

    if (!findEmpty(r, c)) {
        return true;
    }//to check when the board is full

    int digits[9];
    for (int i = 0; i < 9; i++) digits[i] = i + 1; //this creates an array with the 9 digits

    for (int i = 0; i < 9; i++) {
        int j = rand() % 9;
        int temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
    }// and this will shuffle the 9 digits so we have a different board each time

    for (int k = 0; k < 9; k++) {
        int v = digits[k];
        if (validCellPlacement(r, c, v)) {
            setCell(r, c, v);
            if (fillSolutionBacktrack()) return true;
            setCell(r, c, 0);
        }
    }//this will put the number assuming it is correct and continue, when at same point there becomes a problem then it will backtrack to find where was something added wrong
    return false;
}



int Matrix::countSolutionsLimit(int limit) {//this function was made with the help of chatgpt
    Matrix copy = *this;

    int r, c;
    if (!copy.findEmpty(r, c)) {
        return 1;
    }//there is only 1 possible solution of the board then no worries

    int solutions = 0;

    for (int v = 1; v <= 9; v++) {

        if (copy.validCellPlacement(r, c, v)) {//makes a copy so that we do not edit in the actual board
            Matrix next = copy;
            next.setCell(r, c, v);
            solutions += next.countSolutionsLimit(limit - solutions);

            if (solutions >= limit) {
                return solutions;
            }
        }
    }
    return solutions;
}//this is to ensure that each cell can have only 1 possible number to be put in it
//because we were facing the issue before that two numbers work in one place then which one should be picked

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
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if (matrix[i][j]==0) {
                cout << "_| ";
            }
            else {
                cout<<matrix[i][j]<<"| ";
            }
        }
        cout<<endl;
    }

    cout <<endl<<"Done printing";
    return;
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
                if (!m.validCellPlacement(r,c,v)) {
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


Matrix Matrix::generatePuzzle(int dif) {
    int clues;

    if (dif == 1) clues = 35;
    else if (dif == 2) clues = 24;
    else if (dif == 3) clues = 15;
    else clues = 25;//depends on the difficulty

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            setCell(i, j, 0);//empties the entire board first incase

    srand(time(NULL));//for randomness

    if (!fillSolutionBacktrack()) {
        throw runtime_error("Failed to generate full sudoku solution");
    }//we have a full valid solution

    int pos[81][2];
    int idx = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            pos[idx][0] = i;
            pos[idx][1] = j;
            idx++;
        }
    }//an array that stores the different positions on the board in the following form {row,col}, {row,col}.....

    for (int i = 0; i < 81; i++) {
        int j = rand() % 81;
        int r1 = pos[i][0], c1 = pos[i][1];
        int r2 = pos[j][0], c2 = pos[j][1];

        int tr = r1, tc = c1;
        pos[i][0] = r2; pos[i][1] = c2;
        pos[j][0] = tr; pos[j][1] = tc;
    }//randomises the order of the cells in the array

    int currentClues = 81;

    for (int k = 0; k < 81; k++) {//here we will remove in order of the randomized order of cells
        if (currentClues <= clues) break;

        int r = pos[k][0];
        int c = pos[k][1];

        int backup = getCell(r, c);
        setCell(r, c, 0);

        int sol = countSolutionsLimit(2);//this is so that when we remove a number we have to make sure the board still has one unique solution

        if (sol != 1) {//If there are more than 1 not unique anymore undo the removal and if there is 0 which is not possible then something is wrong return the removed number
            setCell(r, c, backup);
        }
        else {
            currentClues--;
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

// FIXED: correct loop conditions (previously used > which never iterated)
bool Matrix::validCellPlacement(int row, int col, int val){
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

bool Matrix::isValid()  {
    if (rows != 9 || cols != 9) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Get the current value in the cell assuming 0 means empty.
            int current_val = getCell(i, j);

            if (current_val != 0) {

                if (!validCellPlacement(i, j, current_val)) {
                    return false; // Conflict found, the entire board is invalid.
                }
            }
        }
    }

    // if all occupied cells pass their respective checks, the board is valid.
    return true;
}

bool Matrix::isComplete() { //Nadine: Added to check if the sudoku is solved
    //if there are no empty cell, solved
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(getCell(i,j) == 0) return false;
        }
    }
    return true;
}
