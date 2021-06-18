//
//  main.cpp
//  Assignment_2
//
//  Created by Nicholas Buras on 6/7/21.
//

// libs
#include <stdio.h>
#include <iostream>
#include <fstream>
//file headers
#include "customErrorClass.h"
#include "BST.hpp"


void readInFile(c_BST&, int&, char[50]);

int main(int argc, const char * argv[]) {
    //vars to hold tree and input
    c_BST myBST;
    char fileName[50] = "assign.dat";
    int input;
    
    
    //read in file, insert values into tree
    try {
        myBST.readInFile(myBST, input, fileName);
    } catch(MyException& error) {
        std::cout << error.what();
    }
    int j;
}

void readInFile(c_BST& myBST, int& input, char inputFile[50]) {
    fstream fileToBeRead(inputFile);
    if(!fileToBeRead.is_open()){
        throw MyException("ERROR: File could not be opened properly. Please check spelling of file name/if it is within the current directory");
    } else {
        fileToBeRead >> input;
        myBST.insertValue(input);
    }
    
}
