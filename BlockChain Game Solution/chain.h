//
//  chain.h
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#ifndef chain_h
#define chain_h

#include "block.h"

class chain {
    int numOfBlocks; //variable to indicate the number of blocks in the chain
public:
    block *blocks; //chain is such that the in-play surfaces are the top, front, bottom, and back (ie blocks l/r sides are touching eachother)
    chain(block *b); //constructor that takes an array of blocks (default 4 blocks)
    chain(block *b, int n); //constructor for explicit amount of blocks
    ~chain(); //destructor
    //void shiftBlocks(); //function to change the order (i think this is unecessary cause the order doesnt matter)
    bool isSolved(); //function to check if the blockchain is solved
    //void rotateBlock(int i, Axis direction); //function to rotate a block - calls the rotateBlock() in block class for a specific block in the chain (this seems redundant but whatever)
};
#endif /* chain_h */
