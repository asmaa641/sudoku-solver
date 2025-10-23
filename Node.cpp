
#include "node.h"


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

void Node::addChild(Node* child){
    if(!child || childCount >= 9) return;
    children[childCount++] = child;
}






