#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Matrix.h"
#include "SudokuSolver.h"

class Node{
   Matrix board;
   Node* parent;
   Node* children[9];
   int childCount;
   SudokuSolver* solver;

   public:
   Node(Matrix b, Node* p);
   ~Node();
   Node* addChild(Node* child);
   Node* populateChildren();
};



#endif