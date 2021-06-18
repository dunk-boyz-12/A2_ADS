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
// files
#include "BST.hpp"
#include "customErrorClass.h"

// CONSTRUCTOR & DESTRUCTOR
c_BST::c_BST() {
    this->root = NULL;
    this->totalNodes = 0;
}

c_BST::~c_BST() {
    //delete tree
}

// PUBLIC FUNCTIONS
void c_BST::readInFile(c_BST& myBST, int& input, char inputFile[50]){
    if(inputFile == NULL){
        throw MyException("ERROR: You must have a file to read from.");
    } else {
        this->p_readInFile(myBST, input, inputFile);
    }
};

void c_BST::insertValue(int value){
    //add exc checks
    s_Node* newNode = this->p_createNode(value);
    if(this->root == NULL){
        this->root = newNode;
    } else {
        this->p_insertValue(this->root,newNode);
    }
};

void c_BST::printTree(){
    this->p_formattedPrint(this->root, 0);
}



// PRIVATE FUNCTIONS
void c_BST::p_readInFile(c_BST& myBST, int& input, char inputFile[50]) {
    //change full path before submitting!!!
    fstream fileToBeRead("/Users/nicholasburas/XcodeProjects/CSC310_ADS_Projects/A2/Assignment_2/Assignment_2/assign.dat");
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

s_Node* c_BST::p_createNode(int value){
    s_Node* newNode = new s_Node;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
};

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
