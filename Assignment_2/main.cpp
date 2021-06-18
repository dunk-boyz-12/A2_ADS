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


int main(int argc, const char * argv[]) {
    //vars to hold tree and input
    c_BST myBST;
    char fileName[50] = "assign.dat";
    int input;
    
    //read in file, insert values into tree
    try {
        myBST.readInFile(myBST, input, fileName);
        myBST.printTree();
        int j;
    } catch(MyException& error) {
        std::cout << error.what();
    }
}

