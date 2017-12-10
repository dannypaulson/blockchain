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
    block blocks[4]; //chain is such that the 4 surfaces are the top, front, bottom, and back
public:
    chain(block b[4]);
    ~chain();
    void shiftBlocks(); //change the order
    bool isSolved();
    void rotateBlock(int i, Axis direction); //i is which block to rotate
};
#endif /* chain_h */
