//
//  block.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include "block.h"
#include <string>

//it wouldnt let me get by without a default constructor so i made one up
block::block() {
    numOfSides = 6;
    name = "";
    orientation = 0;
    sides = new side [numOfSides];
    for (int i = 0; i < numOfSides; i++) {
        sides[i] = side();
    }
}

//overloaded contructor to initialize with an array of sides and a name
block::block(side* sds, std::string nm) {
    numOfSides = 6;
    name = nm;
    orientation = 0;
    sides = new side [numOfSides];
    for (int i = 0; i < numOfSides; i++) {
        sides[i].setColor(sds[i].getColor());
    }
}

//overloaded constructor to initialize with an array of sides, a name, and a number of sides
block::block(side* sds, std::string nm, int n) {
    numOfSides = n;
    name = nm;
    orientation = 0;
    sides = new side [numOfSides];
    for (int i = 0; i < numOfSides; i++) {
        sides[i].setColor(sds[i].getColor());
    }
}

block::~block() {
    //delete [] sides;
}

side* block::getSides() {
    return sides;
}

std::string block::getName() {
    return name;
}

int block::getNumOfSides() {
    return numOfSides;
}

//function to rotate block about specified axis
void block::rotateBlock(Axis direction) {
    if (direction == tb) { //front side moves to left position, right side moves to front, back moves to right, left moves to back
        side *temp = new side(sides[left_].getColor());
        sides[left_] = sides[front_];
        sides[front_] = sides[right_];
        sides[right_] = sides[back_];
        sides[back_] = *temp;
        delete temp;
    }
    else if (direction == lr) { //top moves to front, back moves to top, bottom moves to back, front moves to bottom
        side *temp = new side(sides[top_].getColor());
        sides[top_] = sides[back_];
        sides[back_] = sides[bottom_];
        sides[bottom_] = sides[front_];
        sides[front_] = *temp;
        delete temp;
    }
    else if (direction == fb) { //top moves to right, left moves to top, bottom moves to left, right moves to bottom
        side *temp = new side(sides[top_].getColor());
        sides[top_] = sides[left_];
        sides[left_] = sides[bottom_];
        sides[bottom_] = sides[right_];
        sides[right_] = *temp;
        delete temp;
    }
}

//function to overload operator++ to change orientation of block
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
