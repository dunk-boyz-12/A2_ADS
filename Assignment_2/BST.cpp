//
//  BST.cpp
//  Assignment_2
//
//  Created by Nicholas Buras on 6/7/21.
//

// libs
#include <iostream>
#include <fstream>
// files
#include "BST.hpp"
#include "customErrorClass.h"

// constructor & destructor
c_BST::c_BST() {
    this->root = NULL;
    this->totalNodes = 0;
}

c_BST::~c_BST() {
    //delete tree
}

// public functions
void c_BST::readInFile(c_BST& myBST, int& input, char inputFile[50]){
    this->p_readInFile(myBST, input, inputFile);
};

void c_BST::insertValue(int value){
    //add exc checks
    s_Node* newNode = this->p_createNode(value);
    this->p_insertValue(newNode);
};



// private functions
void c_BST::p_readInFile(c_BST& myBST, int& input, char inputFile[50]) {
    fstream fileToBeRead(inputFile);
    if(!fileToBeRead.is_open()){
        throw MyException("ERROR: File could not be opened properly. Please check spelling of file name/if it is within the current directory");
    } else {
        fileToBeRead >> input;
        myBST.insertValue(input);
    }
    
}

void c_BST::p_insertValue(s_Node* newNode){
    if(this->root == NULL){
        this->root = newNode;
    }
};

s_Node* c_BST::p_createNode(int value){
    s_Node* newNode = new s_Node;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
};
