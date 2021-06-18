//
//  BST.hpp
//  Assignment_2
//
//  Created by Nicholas Buras on 6/7/21.
//

#ifndef BST_HPP
#define BST_HPP

// libs
#include <stdio.h>

struct s_Node {
    int value;
    s_Node* leftChild;
    s_Node* rightChild;
};

class c_BST {
public:
    c_BST();
    ~c_BST();
    //s_Node* createNode(int);
    void readInFile(c_BST&, int&, char[50]);
    void insertValue(int);
    void findNode(s_Node*);
    void printTree();
    void sortTree();
    void getHeight();
    void deleteTree();
private:
    s_Node* root;
    int totalNodes;
    
    void p_readInFile(c_BST&, int&, char[50]);
    void p_rotateRight(s_Node*);
    void p_rotateLeft(s_Node*);
    void p_createVine(s_Node*);
    void p_createTree(s_Node*);
    void p_deleteTree(s_Node*);
    s_Node* p_createNode(int);
    void p_insertValue(s_Node*);
    void p_findNode(s_Node*);
    void p_printTree(s_Node*);
    void p_sortTree(s_Node*);
    void p_getHeight(s_Node*);
};

#endif /* BST_HPP */