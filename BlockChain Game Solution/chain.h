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
    
public:
    block blocks[4]; //chain is such that the 4 in-play surfaces are the top, front, bottom, and back (ie blocks l/r sides are touching eachother)
    chain(block b[4]); //constructor that takes an array of 4 blocks
    ~chain(); //destructor
    //void shiftBlocks(); //function to change the order (i think this is unecessary cause the order doesnt matter)
    bool isSolved(); //function to check if the blockchain is solved
    //void rotateBlock(int i, Axis direction); //function to rotate a block - calls the rotateBlock() in block class for a specific block in the chain (this seems redundant but whatever)
};
#endif /* chain_h */
