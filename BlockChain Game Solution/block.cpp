//
//  block.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include <stdio.h>
#include "block.h"
#include <string>

using namespace std;

block::block() {
    for (int i = 0; i < 6; i++) {
        sides[i] = side();
    }
    name = "";
}

block::block(side* sds, string nm) {
    for (int i = 0; i < 6; i++) {
        sides[i] = sds[i];
    }
    name = nm;
}

block::~block() {
    
}

side* block::getSides() {
    return sides;
}

void block::rotateBlock(Axis direction) {
    if (direction == tb) {
        //front side moves to left position, right side moves to front, back moves to right, left moves to back
        side temp(sides[left].getColor());
        sides[left] = sides[front];
        sides[front] = sides[right];
        sides[right] = sides[back];
        sides[back] = temp;
    }
    else if (direction == lr) {
        //top moves to front, back moves to top, bottom moves to back, front moves to bottom
        side temp(sides[top].getColor());
        sides[top] = sides[back];
        sides[back] = sides[bottom];
        sides[bottom] = sides[front];
        sides[front] = temp;
    }
    else if (direction == fb) {
        //top moves to right, left moves to top, bottom moves to left, right moves to bottom
        side temp(sides[top].getColor());
        sides[top] = sides[left];
        sides[left] = sides[bottom];
        sides[bottom] = sides[right];
        sides[right] = temp;
    }
}
