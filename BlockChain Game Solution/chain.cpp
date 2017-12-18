//
//  chain.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include <iostream>
#include "chain.h"

//constructor to create chain from an array of blocks (default 4)
chain::chain(block *b) {
    numOfBlocks = 4;
    blocks = new block[numOfBlocks];
    for (int i = 0; i < numOfBlocks; i++) {
        for (int j = 0; j < b[i].getNumOfSides(); j++) {
            Color c = b[i].getSides()[j].getColor();
            blocks[i].getSides()[j].setColor(c);
        }
    }
}

//constructor to create chain from an array of blocks of size n
chain::chain(block *b, int n) {
    numOfBlocks = n;
    blocks = new block[numOfBlocks];
    for (int i = 0; i < numOfBlocks; i++) {
        for (int j = 0; j < b[i].getNumOfSides(); j++) {
            Color c = b[i].getSides()[j].getColor();
            blocks[i].getSides()[j].setColor(c);
        }
    }
}

chain::~chain() {
    delete[] blocks;
}


/*
void chain::shiftBlocks() {
    block temp = blocks[0];
    blocks[0] = blocks[1];
    blocks[1] = blocks[2];
    blocks[2] = blocks[3];
    blocks[3] = temp;
}
*/

//function to check if the chain is solved
bool chain::isSolved() {
    //look at each edge one at a time
    for (int edge = top_; edge <= right_; edge++) {
        
        //compare the colors of the blocks
        for (int i = 0; i < numOfBlocks - 1; i++) {
            
            for (int j = i + 1; j < numOfBlocks; j++) {
                
                //if they are the same color then it's not solved yet
                if (blocks[i].getSides()[edge].getColor() == blocks[j].getSides()[edge].getColor()) {
                    
                    return false;
                }
            }
        }
    }
    
    //if we get here there are no duplicates so it is solved
    return true;
}

//function to rotate a specific block in the chain
/*
void chain::rotateBlock(int i, Axis direction) { //rotate block i about axis direction
    blocks[i].rotateBlock(direction);
}
*/
