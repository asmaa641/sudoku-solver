
#include "Node.h"
#include "Matrix.h"


Node::Node(Matrix b, Node* p) : board(b), parent(p), childCount(0) {
    for (int i = 0; i < 9; ++i) {
        children[i] = 0;
    }
}

Node::~Node(){
    for(int i = 0; i < 9; i++){
        delete children[i];
    }
}

Node* Node::addChild(int row, int coloumn, int val){
    if(childCount >= 9) return nullptr;
    Matrix newBoard = board; 
    newBoard.set(row, coloumn, val);
    Node* child = new Node(newBoard, this);
    children[childCount++] = child;
    return child;
}






