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