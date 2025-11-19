//
// Created by Arwa Hassan on 23/10/2025.
//

#include "SudokuSolver.h"
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

namespace {
    // yay we're using bits again
    constexpr int ALL_BITS = 0x3FE; // binary: 11 1111 1110

    inline int blockIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    // count bits set (use builtin for simplicity)
    inline int bitCount(int x) {
        return __builtin_popcount((unsigned)x);
    }

    // produce vector of candidate values from mask (values 1..9)
    inline std::vector<int> valuesFromMask(int mask) {
        std::vector<int> vals;
        while (mask) {
            int bit = mask & -mask;
            int v = __builtin_ctz((unsigned)bit); // v is the bit index, equals value
            vals.push_back(v);
            mask &= mask - 1;
        }
        return vals;
    }

    // Recursive solver using MRV + forward checking + LCV-ish ordering
    static bool solveRec(Matrix &board,
                         std::array<int,9> &rowMask,
                         std::array<int,9> &colMask,
                         std::array<int,9> &blkMask)
    {
        // find the unassigned cell with minimum remaining values (MRV)
        int bestR = -1, bestC = -1;
        int bestCount = 10;
        int bestMask = 0;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board.getCell(r,c) == 0) {
                    int b = blockIndex(r,c);
                    int mask = ~(rowMask[r] | colMask[c] | blkMask[b]) & ALL_BITS;
                    int cnt = bitCount(mask);
                    if (cnt == 0) {
                        // no possible value -> fail early
                        return false;
                    }
                    if (cnt < bestCount) {
                        bestCount = cnt;
                        bestR = r;
                        bestC = c;
                        bestMask = mask;
                        if (bestCount == 1) break; // can't do better
                    }
                }
            }
            if (bestCount == 1) break;
        }

        if (bestR == -1) {
            // no empty cell -> solved
            return true;
        }

        // Value ordering: compute a simple least-constraining metric for each candidate
        std::vector<std::pair<int,int>> cand; // (elimCount, value)
        {
            std::vector<int> vals = valuesFromMask(bestMask);
            for (int v : vals) {
                int elim = 0;
                // Count how many neighbors would lose this candidate
                // row neighbors
                for (int cc = 0; cc < 9; ++cc) {
                    if (cc == bestC) continue;
                    if (board.getCell(bestR, cc) != 0) continue;
                    int nbMask = ~(rowMask[bestR] | colMask[cc] | blkMask[blockIndex(bestR,cc)]) & ALL_BITS;
                    if (nbMask & (1 << v)) ++elim;
                }
                // col neighbors
                for (int rr = 0; rr < 9; ++rr) {
                    if (rr == bestR) continue;
                    if (board.getCell(rr, bestC) != 0) continue;
                    int nbMask = ~(rowMask[rr] | colMask[bestC] | blkMask[blockIndex(rr,bestC)]) & ALL_BITS;
                    if (nbMask & (1 << v)) ++elim;
                }
                // block neighbors
                int br = (bestR / 3) * 3;
                int bc = (bestC / 3) * 3;
                for (int dr = 0; dr < 3; ++dr) {
                    for (int dc = 0; dc < 3; ++dc) {
                        int rr = br + dr;
                        int cc = bc + dc;
                        if (rr == bestR && cc == bestC) continue;
                        if (board.getCell(rr,cc) != 0) continue;
                        int nbMask = ~(rowMask[rr] | colMask[cc] | blkMask[blockIndex(rr,cc)]) & ALL_BITS;
                        if (nbMask & (1 << v)) ++elim;
                    }
                }
                cand.emplace_back(elim, v);
            }
            // sort ascending by eliminations => try least-constraining first
            std::sort(cand.begin(), cand.end());
        }

        // Try each candidate value
        for (auto &p : cand) {
            int v = p.second;
            // assign
            board.setCell(bestR, bestC, v);
            rowMask[bestR] |= (1 << v);
            colMask[bestC] |= (1 << v);
            blkMask[blockIndex(bestR,bestC)] |= (1 << v);

            // recurse
            if (solveRec(board, rowMask, colMask, blkMask)) {
                return true;
            }

            // undo
            board.setCell(bestR, bestC, 0);
            rowMask[bestR] &= ~(1 << v);
            colMask[bestC] &= ~(1 << v);
            blkMask[blockIndex(bestR,bestC)] &= ~(1 << v);
        }

        return false; // no candidate led to solution
    }
} // end anon namespace

// SudokuSolver::solve: this is supposed to return a Node containing the solved board if solved,
// otherwise returns a Node containing the original board.
Node SudokuSolver::solve(Matrix &board) {
    // work on a copy so we don't unexpectedly mutate caller's board
    Matrix working = board;

    // initialize masks from the starting board
    std::array<int,9> rowMask = {0}, colMask = {0}, blkMask = {0};

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int val = working.getCell(r,c);
            if (val > 0 && val <= 9) {
                int b = blockIndex(r,c);
                // if conflicting initial puzzle, print warning (student-style)
                if ( (rowMask[r] & (1<<val)) || (colMask[c] & (1<<val)) || (blkMask[b] & (1<<val)) ) {
                    std::cout << "Warning: initial board has a conflict at (" << r << "," << c << ") value " << val << "\n";
                }
                rowMask[r] |= (1<<val);
                colMask[c] |= (1<<val);
                blkMask[b] |= (1<<val);
            }
        }
    }

    bool solved = solveRec(working, rowMask, colMask, blkMask);

    if (solved) {
        // return Node with solved board
        return Node(working, nullptr);
    } else {
        std::cout << "SudokuSolver::solve: no solution found\n";
        return Node(board, nullptr);
    }
}