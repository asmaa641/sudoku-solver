cmake_minimum_required(VERSION 3.20)
project(SudokuSolver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sudoku-solver
        main.cpp
       Matrix.cpp
        Node.cpp
        SudokuSolver.cpp
)

target_include_directories(sudoku-solver PRIVATE include)