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
    int getHeight();
    void deleteTree();
private:
    s_Node* root;
    int totalNodes;
    
    void p_readInFile(c_BST&, int&, char[50]);
    void p_rotateRight(s_Node*);
    void p_rotateLeft(s_Node*);
    void p_createVine();
    void p_createTree();
    void p_deleteTree(s_Node*);
    s_Node* p_createNode(int);
    s_Node* p_insertValue(s_Node*, s_Node*);
    void p_findNode(s_Node*);
    void p_printTree(s_Node*);
    void p_sortTree(s_Node*);
    int p_getHeight(s_Node*);
    void p_formattedPrint(s_Node*, int);
};

#endif /* BST_HPP */
