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
    //variable to indicate the number of blocks in the chain
    int numOfBlocks;
    
public:
    //dynamically allocated array of blocks that make up the chain
    block *blocks;
    /*
     chain is such that the in-play surfaces are the top, front, left, and right (ie blocks t/bt sides are touching eachother)
     */
    
    //constructor that takes an array of blocks (default 4 blocks)
    chain(block *b);
    
    //constructor for explicit amount of blocks
    chain(block *b, int n);
    
    //destructor
    ~chain();
    
    //function to change the order (i think this is unecessary cause the order doesnt matter)
    //void shiftBlocks();
    
    //function to check if the blockchain is solved
    bool isSolved();
    
    //function to rotate a block - calls the rotateBlock() in block class for a specific block in the chain
    //void rotateBlock(int i, Axis direction);
};

#endif /* chain_h */
