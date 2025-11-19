
#include "Node.h"
#include "Matrix.h"


Node::Node(Matrix b, Node* p) : board(b), parent(p), childCount(0) {
    for (int i = 0; i < 9; ++i) {
        children[i] = nullptr;
    }
    populateChildren();
}

Node::~Node(){
    for(int i = 0; i < 9; i++){
        delete children[i];
    }
}

Node* Node::addChild(int row, int col, int val){
    if(childCount >= 9) return nullptr;
    Matrix newBoard = board; 
    newBoard.setCell(row, col, val);
    Node* child = new Node(newBoard, this);
    children[childCount++] = child;
    return child;
}

void Node::populateChildren(){
    int r, c;
    if(!board.findEmpty(r, c)) return; // if empty box found, r and c become the coordinates of this box

    for(int i = 1; i <= 9; i++){
        if(board.isValid(r,c,i)){
            addChild(r,c,i);
        }
    }
}
   





