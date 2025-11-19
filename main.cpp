//
// Created by Arwa Hassan on 23/10/2025.
//

#include <iostream>
#include <ostream>
#include "Matrix.h"
#include "SudokuSolver.h"

//Nadine: just trying the code out to see what needs to be fixed, the code will generate error that's normal
int main() {
    srand(time(0));
    Matrix puzzle;
    puzzle.generatePuzzle(2);
    std::cout << "Generated puzzle:\n";
    puzzle.print();

    SudokuSolver solver;
    Node root = solver.solve(puzzle);
    std::cout << "\nSolved? " << (puzzle.isSolved() ? "Yes" : "No") << "\n";
    if (puzzle.isSolved()) {
        puzzle.print();

    }
    return 0;
}