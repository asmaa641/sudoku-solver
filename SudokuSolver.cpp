//
// Created by Arwa Hassan on 23/10/2025.
//

#include "SudokuSolver.h"


Node SudokuSolver::solve(Node& head) {
    cout << "we are at point 1";


    if (!head.board.isValid()) {
        return Node();
    }
    cout << "we are at point 2";


    if (head.board.isComplete()) {
        return head;
    }
    cout << "we are at point 3";
    head.generateChildren();

    for (size_t i = 0; i < 5; ++i) {

        Node solution = solve(*head.children[i]);

        if (solution.board.isComplete()) {
            return solution; // returning solution !! yayyy
        }
    }
    return Node(); //go backkkkk
}