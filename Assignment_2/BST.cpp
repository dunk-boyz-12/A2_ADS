//
//  BST.cpp
//  Assignment_2
//
//  Created by Nicholas Buras on 6/7/21.
//

// libs
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
// files
#include "BST.hpp"
#include "customErrorClass.h"

// CONSTRUCTOR & DESTRUCTOR
/*
 **    Author: Nick Buras
 **    Function Purpose: initiliaze BST data structure
 **
 **    Function Output: None
 **    Side Effects: BST class object is created
 */
c_BST::c_BST() {
    this->root = NULL;
    this->totalNodes = 0; //  NODE COUNT IS OFF BY +1
}
/*
 **    Author: Nick Buras
 **    Function Purpose: delete BST data structure
 **
 **    Function Output: None
 **    Side Effects: BST data structure and nodes are deleted, memory deallocated
 */
c_BST::~c_BST() {
    //delete tree
}

// PUBLIC FUNCTIONS
/*
 **    Author: Nick Buras
 **    Function Purpose: Read input file to fill BST
 **
 **    Function Output: None
 **    Side Effects: private read function is called
 */
void c_BST::readInFile(c_BST& myBST, int& input, char inputFile[50]){
    if(inputFile == NULL){
        throw MyException("ERROR: You must have a file to read from.");
    } else {
        this->p_readInFile(myBST, input, inputFile);
    }
};
/*
 **    Author: Nick Buras
 **    Function Purpose: Insert integer value into tree
 **
 **    Function Output: Node is created with value from file and insterted into tree
 **    Side Effects: total Nodes counter is incremented, private function is called
 */
void c_BST::insertValue(int value){
    s_Node* newNode = this->p_createNode(value);
    if(newNode == NULL){
        throw MyException("ERROR: Node to be added was not created correctly.");
    } else {
        if(this->root == NULL){
            this->root = newNode;
        } else {
            this->root = this->p_insertValue(this->root,newNode);
        }
        this->totalNodes++;
    }
};
/*
 **    Author: Nick Buras
 **    Function Purpose: print tree in BST format
 **
 **    Function Output: Tree is printed to the console
 **    Side Effects: private function is called
 */
void c_BST::printTree(){
    if(this->root == NULL){
        throw MyException("ERROR: Tree is empty.");
    } else {
        this->p_formattedPrint(this->root, 0);
    }
}
/*
 **    Author: Nick Buras
 **    Function Purpose: Get height of current tree
 **
 **    Function Output: Tree height
 **    Side Effects: None
 */
int c_BST::getHeight(){
    int treeHeight;
    if(this->root == NULL){
        throw MyException("ERROR: Tree is empty. Height is 0.");
    } else {
        treeHeight = this->p_getHeight(this->root);
    }
    return treeHeight;
}
/*
 **    Author: Nick Buras
 **    Function Purpose: Delete tree DS
 **
 **    Function Output: None
 **    Side Effects: private delete is called
 */
void c_BST::deleteTree(){
    if(this->root == NULL){
        throw MyException("ERROR: Tree is empty. Height is 0.");
    } else {
        this->p_deleteTree(this->root);
    }
}
/*
 **    Author: Nick Buras
 **    Function Purpose: Sort tree using DSW algo
 **
 **    Function Output: balanced DSW tree
 **    Side Effects: private functions are called for right and left rotations
 */
void c_BST::sortTree(){
    if(this->root == NULL){
        throw MyException("Tree is empty.");
    } else {
        this->p_createVine();
        this->p_createTree();
    }
};

// PRIVATE FUNCTIONS
/*
 **    Author: Nick Buras
 **    Function Purpose: Read input file to fill BST
 **
 **    Function Output: None
 **    Side Effects: insert is called, file is opened and closed
 */
void c_BST::p_readInFile(c_BST& myBST, int& input, char inputFile[50]) {
    //change full path before submitting!!!
    //fstream fileToBeRead("/Users/nicholasburas/XcodeProjects/CSC310_ADS_Projects/A2/Assignment_2/Assignment_2/assign.dat");
    fstream fileToBeRead("assign.dat");
    if(!fileToBeRead.is_open()){
        throw MyException("ERROR: File could not be opened properly. Please check spelling of file name/if it is within the current directory.");
    } else {
        while(!fileToBeRead.eof()){
            fileToBeRead >> input;
            myBST.insertValue(input);
        }
        fileToBeRead.close();
    }
}
/*
 **    Author: Nick Buras
 **    Function Purpose: Insert integer value into tree if not root
 **
 **    Function Output: None
 **    Side Effects: Node is added to tree
 */
s_Node* c_BST::p_insertValue(s_Node* root, s_Node* newNode){
    if(root == NULL) {
        return newNode;
    } else {
        if(newNode->value < root->value){
            root->leftChild = this->p_insertValue(root->leftChild, newNode);
        } else {
            root->rightChild = this->p_insertValue(root->rightChild, newNode);
        }
    }
    return root;
};
/*
 **    Author: Nick Buras
 **    Function Purpose: Create node to insert into tree
 **
 **    Function Output: newly created node
 **    Side Effects: node object value and pointers are updated
 */
s_Node* c_BST::p_createNode(int value){
    if(value <= -1) {
        throw MyException("ERROR: The value to be inserted into the newly created node must be a positive integer value.");
    } else {
        s_Node* newNode = new s_Node;
        newNode->value = value;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
};
/*
 **    Author: Alex Wolman
 **    Function Purpose: Print formatted Tree
 **
 **    Function Output: Tree
 **    Side Effects: None
 */
void c_BST::p_formattedPrint(s_Node* node, int indent){
    if( NULL == node ){
        return;
    } else {
        this->p_formattedPrint(node->leftChild, indent+4);
        if( indent ){
            cout<<setw(indent)<<" ";
        }
        cout<<node->value<<endl;
        this->p_formattedPrint(node->rightChild, indent+4);
    }
}
/*
 **    Author:
 **    Function Purpose:
 **
 **    Function Output:
 **    Side Effects:
 */
int c_BST::p_getHeight(s_Node* root){
    return 0;
}
/*
 **    Author:
 **    Function Purpose:
 **
 **    Function Output:
 **    Side Effects:
 */
void c_BST::p_deleteTree(s_Node* root){
    
}
/*
 **    Author: Nick Buras
 **    Function Purpose: Rotate a node to the right
 **
 **    Function Output: None
 **    Side Effects: Tree structure is changed from rotation
 */
void c_BST::p_rotateRight(s_Node* root){
    //vars to keep track of all nodes we might need
    s_Node* currentParent = root;
    s_Node* currentLeftChild = root->leftChild;
    s_Node* currentRightChild = root->rightChild;
    s_Node* currentBiggerLeftGrandChild = root->leftChild->rightChild;
    s_Node* currentSmallerLeftGrandChild = root->leftChild->leftChild;
    //swap currentNode with leftChild, without this I  kept losing right sub tree since I wasnt preserving the rightChild ptr from previous parent
    int parentValue = currentParent->value;
    currentParent->value = currentLeftChild->value;
    currentLeftChild->value = parentValue;
    //reposition pointers
    currentParent->leftChild = currentSmallerLeftGrandChild;
    currentParent->rightChild = currentLeftChild;
    currentLeftChild->rightChild = currentRightChild;
    currentLeftChild->leftChild = currentBiggerLeftGrandChild;
};
/*
 **    Author: Nick Buras
 **    Function Purpose: Rotate a node to the left, Does not work correctly
 **
 **    Function Output: None
 **    Side Effects: Tree structure is changed from rotation
 */
void c_BST::p_rotateLeft(s_Node* node){
    //vars to keep track of all nodes we might need
    s_Node* currNode = node;
    s_Node* currentRightChild = currNode->rightChild;
    //s_Node* currentLeftChild = currNode->leftChild;
    s_Node* currentRightLeftChild = currNode->leftChild;
    //reposition pointers
    currentRightChild->leftChild = currNode;
    currNode->rightChild = currentRightLeftChild;
    this->root = currentRightChild;
};
/*
 **    Author: Nick Buras
 **    Function Purpose: Create Vine from Tree
 **
 **    Function Output: None
 **    Side Effects: Tree structure is changed into linked list
 */
void c_BST::p_createVine(){
    s_Node* counterNode = this->root;
    while (counterNode != NULL) {
        if(counterNode->leftChild){
            this->p_rotateRight(counterNode);
        }
        else {
            counterNode = counterNode->rightChild;
        }
    }
};
/*
 **    Author: Nick Buras
 **    Function Purpose: create tree from vine using dsw algo
 **
 **    Function Output: none
 **    Side Effects: Tree strucutre is balanced using dsw algo
 */
void c_BST::p_createTree(){
    //find height of closest perfectly balanced tree
    int pHeight = floor(log2(totalNodes));
    //number of nodes in closeset perfectly balanced tree of pHeight
    int pNodes = pow(2,pHeight);
    //find number of leftmost bottom nodes for initial rotations
    int initialRotations = totalNodes - pNodes;
    //initial rotations
    s_Node* rotateNode = this->root;
    s_Node* nextNode = this->root->rightChild;
    for(int counter = initialRotations; counter > 0; counter--){
        this->p_rotateLeft(rotateNode);
        nextNode = nextNode->rightChild;
        rotateNode = nextNode;
    }
};
