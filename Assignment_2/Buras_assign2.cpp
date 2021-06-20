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
#include <math.h>
//file headers
#include "customErrorClass.h"
#include "BST.hpp"


int main(int argc, const char * argv[]) {
    //vars to hold tree and input
    c_BST myBST;
    char fileName[50] = "assign.dat";
    int input;

    try {
        //read in file, insert values into tree
        myBST.readInFile(myBST, input, fileName);
        //print tree before sorting
        myBST.printTree();
        //DSW Sort
        myBST.sortTree();
        //print tree after sorting
        myBST.printTree();
        
    } catch(MyException& error) {
        std::cout << error.what();
    } catch(exception& error) {
        std::cout << error.what();
    }
}

