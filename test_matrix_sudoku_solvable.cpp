//
// Created by Nadine Donia on 29/11/2025.
//
#include <gtest/gtest.h>
#include "Matrix.h"

//hii, so we first solve the puzzle using Matrix's backtracking solver

static bool solvePuzzle(const Matrix& puzzle, Matrix& outSolution) {
    outSolution = puzzle;            // deep copy via operator=
    return outSolution.fillSolutionBacktrack();
}

// so we need to ensure that a generated puzzle is:
// 1. a valid partial Sudoku (no rule violations in the given clues)
// 2. solvable by the backtracking solver (at least one solution exists)
TEST(MatrixSudokuTest, GeneratedPuzzleIsSolvable_EasyDifficulty) {
    Matrix generator;

    // generate a puzzle of chosen difficulty (1=easiest)
    Matrix puzzle = generator.generatePuzzle(1);

    // 1) the initial puzzle should be a valid Sudoku configuration
    EXPECT_TRUE(puzzle.isValid()) << "Generated puzzle is not internally valid.";

    // 2) try to solve the puzzle using the same backtracking solver
    Matrix solution;
    bool solved = solvePuzzle(puzzle, solution);

    EXPECT_TRUE(solved) << "Generated puzzle appears to be unsolvable by backtracking solver.";

    // 3) solution should be valid and complete.
    EXPECT_TRUE(solution.isValid()) << "Solver produced an invalid Sudoku solution.";
    EXPECT_TRUE(solution.isComplete()) << "Solver did not fully fill the Sudoku board.";
}

// we can also test multiple difficulties
TEST(MatrixSudokuTest, GeneratedPuzzleIsSolvable_MediumAndHard) {
    for (int dif : {2, 3}) {
        Matrix generator;
        Matrix puzzle = generator.generatePuzzle(dif);

        EXPECT_TRUE(puzzle.isValid()) << "Generated puzzle (difficulty " << dif
                                      << ") is not internally valid.";

        Matrix solution;
        bool solved = solvePuzzle(puzzle, solution);

        EXPECT_TRUE(solved) << "Generated puzzle (difficulty " << dif
                            << ") appears to be unsolvable by backtracking solver.";
        EXPECT_TRUE(solution.isValid()) << "Solution (difficulty " << dif << ") is invalid.";
        EXPECT_TRUE(solution.isComplete()) << "Solution (difficulty " << dif << ") is incomplete.";
    }
}