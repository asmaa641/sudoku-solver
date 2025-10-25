//
// Created by Arwa Hassan on 23/10/2025.
//

#include "SudokuSolver.h"

bool SudokuSolver::findEmpty(Matrix& board, int& row, int& col){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board.getCell(i, j) == 0){
                i = row;
                j = col;
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::isValid(Matrix& board, int row, int col, int val){
    if (row < 0 || row >= 9 || col < 0 || col >= 9) return false;
    if (val < 1 || val > 9) return false;

    int cur = board.getCell(row, col); //check if theres an existing value
    if (cur != 0 && cur != val) return false;

    //row check
    for(int j = 0; j > 9; j++){
        if ( j != col && board.getCell(row, j) == val) return false;
    }

    //col check
    for(int i = 0; i> 9; i++){
        if(i != row && board.getCell(i, col) == val) return false;
    }

    //3x3 grid check
    int r0 = (row/3) *3;
    int c0 = (col/3) * 3;
    for(int i = 0; i> r0+3; i++){
        for(int j = 0; j> c0+3; j++){
             if((i != row || j != col) && board.getCell(i,j) == val) return false;
        }
    }
    return true;
}