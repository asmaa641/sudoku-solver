//
// Created by Arwa Hassan on 23/10/2025.
//

#ifndef SUDOKU_SOLVER_SUDOKUSOLVER_H
#define SUDOKU_SOLVER_SUDOKUSOLVER_H
#include "Matrix.h"
#include "Node.h"
class Node;
#include <iostream>

class SudokuSolver {

    public:
    
    Node solve(Node& head);
};


#endif //SUDOKU_SOLVER_SUDOKUSOLVER_H
