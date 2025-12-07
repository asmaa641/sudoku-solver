#include <iostream>
#include "Matrix.h"

int main() {
    try {
        Matrix m;

        // Generate a puzzle with difficulty 1 (easy).
        Matrix puzzle = m.generatePuzzle(1);

        std::cout << "Generated Sudoku puzzle:\n";
        puzzle.print();
        std::cout << "\n";

        // Solve the puzzle to verify (optional demo).
        Matrix solution = puzzle;
        if (solution.fillSolutionBacktrack()) {
            std::cout << "Solved Sudoku:\n";
            solution.print();
            std::cout << "\n";
        } else {
            std::cout << "Failed to solve the generated puzzle.\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}