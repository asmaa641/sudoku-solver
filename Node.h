#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Matrix.h"
#include "SudokuSolver.h"
class SudokuSolver;
class Matrix;

class Node{
   //Matrix board;
   Node* parent;
   Node* children[9];
   int childCount;
   // SudokuSolver* solver; u dont need this just make the functions in the class static fxns
friend class SudokuSolver;
public:
   Matrix board; // made it public bec im trying to use it main revert this later thanks -arwa
   Node(Matrix b, Node* p);
   Node();
   ~Node();
   Node* addChild(int row, int col, int val);
   void populateChildren();
   void generateChildren();
};



#endif