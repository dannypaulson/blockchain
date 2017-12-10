//
//  chain.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include <stdio.h>
#include "chain.h"

chain::chain(block b[4]) {
    for (int i = 0; i < 3; i++) {
        blocks[i] = b[i];
    }
}

chain::~chain() {
    
}

void chain::shiftBlocks() {
    block temp = blocks[0];
    blocks[0] = blocks[1];
    blocks[1] = blocks[2];
    blocks[2] = blocks[3];
    blocks[3] = temp;
}

bool chain::isSolved() {
    Color tops[4];
    Color fronts[4];
    Color bottoms[4];
    Color backs[4];
    for (int i = 0; i < 4; i++) {
        tops[i] = blocks[i].getSides()[top].getColor();
        fronts[i] = blocks[i].getSides()[front].getColor();
        bottoms[i] = blocks[i].getSides()[bottom].getColor();
        backs[i] = blocks[i].getSides()[back].getColor();
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++)
            if (tops[i] == tops[j] || fronts[i] == fronts[j] || bottoms[i] == bottoms[j] || backs[i] == backs[j]) {
                return false;
            }
    }
    return true;
}

void chain::rotateBlock(int i, Axis direction) {
    blocks[i].rotateBlock(direction);
}
