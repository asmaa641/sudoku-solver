cmake_minimum_required(VERSION 3.20)
project(SudokuSolver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/googletest)

add_executable(sudoku-solver
        main.cpp
        Matrix.cpp
        Node.cpp
        SudokuSolver.cpp
)

target_include_directories(sudoku-solver PRIVATE include)

add_executable(matrix_sudoku_tests
        Matrix.cpp
        Node.cpp
        SudokuSolver.cpp
        test_matrix_sudoku_solvable.cpp
        test_node.cpp
)

target_link_libraries(matrix_sudoku_tests
        PRIVATE
        gtest
        gtest_main
)

target_include_directories(matrix_sudoku_tests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/external/googletest/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}
)

enable_testing()
add_test(NAME MatrixSudokuSolvableTest COMMAND matrix_sudoku_tests)