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

block::block() { //it wouldnt let me get by without a default constructor so i made one up
    for (int i = 0; i < 6; i++) {
        sides[i] = side();
    }
    name = "";
    orientation = 0;
}

block::block(side* sds, string nm) { //initialize with an array of sides and a name
    for (int i = 0; i < 6; i++) {
        sides[i] = sds[i];
    }
    name = nm;
    orientation = 0;
}

block::~block() {
    
}

side* block::getSides() { //pretty self explanatory
    return sides;
}

std::string block::getName() {
    return name;
}

void block::rotateBlock(Axis direction) {
    if (direction == tb) {
        //front side moves to left position, right side moves to front, back moves to right, left moves to back
        side temp(sides[leftSide].getColor());
        sides[leftSide] = sides[front];
        sides[front] = sides[rightSide];
        sides[rightSide] = sides[back];
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
        sides[top] = sides[leftSide];
        sides[leftSide] = sides[bottom];
        sides[bottom] = sides[rightSide];
        sides[rightSide] = temp;
    }
}

block& block::operator++() {
    if (orientation >= 0 && orientation <= 2) {
        rotateBlock(tb);
        orientation++;
    }
    else if (orientation == 3) {
        rotateBlock(tb);
        rotateBlock(lr);
        orientation++;
    }
    else if (orientation >= 4 && orientation <= 6) {
        rotateBlock(tb);
        orientation++;
    }
    else if (orientation == 7) {
        rotateBlock(tb);
        rotateBlock(lr);
        orientation++;
    }
    else if (orientation >= 8 && orientation <= 10) {
        rotateBlock(tb);
        orientation++;
    }
    else if (orientation == 11) {
        rotateBlock(tb);
        rotateBlock(lr);
        orientation++;
    }
    else if (orientation >= 12 && orientation <= 14) {
        rotateBlock(tb);
        orientation++;
    }
    else if (orientation == 15) {
        rotateBlock(tb);
        rotateBlock(lr);
        rotateBlock(fb);
        orientation++;
    }
    else if (orientation >= 16 && orientation <= 18) {
        rotateBlock(tb);
        orientation++;
    }
    else if (orientation == 19) {
        rotateBlock(tb);
        rotateBlock(fb);
        rotateBlock(fb);
        orientation++;
    }
    else if (orientation >= 20 && orientation <= 22) {
        rotateBlock(tb);
        orientation++;
    }
    else if (orientation == 23) {
        rotateBlock(tb);
        rotateBlock(fb);
        orientation = 0;
    }
    
    return *this;
}
