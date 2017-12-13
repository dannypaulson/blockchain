//
//  chain.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include <iostream>
#include "chain.h"

chain::chain(block b[4]) { //create chain from an array of blocks
    for (int i = 0; i < 4; i++) {
        blocks[i] = b[i];
    }
}

chain::~chain() {
    
}
/*
void chain::shiftBlocks() { //just rearrange the array of blocks (again wont change the solution)
    block temp = blocks[0];
    blocks[0] = blocks[1];
    blocks[1] = blocks[2];
    blocks[2] = blocks[3];
    blocks[3] = temp;
}
*/
bool chain::isSolved() { //read all of the colors of the tops, bottoms, fronts, and backs of the four blocks into arrays
    Color tops[4];
    Color fronts[4];
    Color bottoms[4];
    Color backs[4];
    for (int i = 0; i < 4; i++) {
        tops[i] = blocks[i].getSides()[top].getColor(); //lol these are confusing but they just get the colors
        fronts[i] = blocks[i].getSides()[front].getColor();
        bottoms[i] = blocks[i].getSides()[bottom].getColor();
        backs[i] = blocks[i].getSides()[back].getColor();
    }
    for (int i = 0; i < 3; i++) { //check if there are any duplicates in any of the arrays - the object of the game is to not have duplicates
        for (int j = i + 1; j < 4; j++)
            if (tops[i] == tops[j] || fronts[i] == fronts[j] || bottoms[i] == bottoms[j] || backs[i] == backs[j]) {
                return false; //if there are duplicates, return false cause its not solved yet
            }
    }
    return true; //if we get here there are no duplicates so it is solved
}
/*
void chain::rotateBlock(int i, Axis direction) { //rotate block i about axis direction
    blocks[i].rotateBlock(direction);
}
*/
