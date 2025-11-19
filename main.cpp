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
    cout << "Point in main1";
    Node* ptr;
    Node testNode= Node(puzzle, ptr);
    cout << "Point in main2";
    Node root = SudokuSolver::solve(testNode);
    std::cout << "\nSolved? " << (root.board.isComplete() ? "Yes" : "No") << "\n";
    if (root.board.isComplete()) {
        root.board.print();

    }
    return 0;
}