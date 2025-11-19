//
// Created by Arwa Hassan on 23/10/2025.
//

#include "SudokuSolver.h"


Node SudokuSolver::solve(Node& head) {
    if (!head.board.isValid()) {
        return Node();
    }

    if (head.board.isComplete()) {
        return head;
    }

    head.populateChildren();

    for (int i = 0; i < head.childCount; ++i) {
        Node solution = solve(*head.children[i]);
        if (solution.board.isComplete()) {
            return solution;
        }
    }
    return Node();
}