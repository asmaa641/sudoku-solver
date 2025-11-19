//
// Created by Arwa Hassan on 23/10/2025.
//

#include "SudokuSolver.h"

Node SodukuSolver::solve(Node& head) {

        if (!head.matrix.isValid()) {
            return Node();
        }

        if (head.matrix.isComplete()) {
            return head;
        }

        head.generateChildren();

        for (size_t i = 0; i < children.size(); ++i) {

            Node solution = solve(children[i]);

            if (solution.matrix.isComplete()) {
                return solution; // returning solution !! yayyy
            }
        }
        return Node(); //go backkkkk
    }