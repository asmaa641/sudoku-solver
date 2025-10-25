#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Matrix.h"

class Node{
   Matrix board;
   Node* parent;
   Node* children[9];
   int childCount;

   public:
   Node(Matrix b, Node* p);
   ~Node();
   void addChild(Node* child);

};



#endif