//
//  block.h
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#ifndef block_h
#define block_h

#include "side.h"
#include <string>

enum Axis {tb, lr, fb}; //tb is top-bottom axis, lr is left-rigth axis, fb is front/back axis
                        //spin direction is clockwise as seen from first side in pair (ie as seen from top, left, and front)
enum Sides {top, bottom, leftSide, rightSide, front, back};

class block {
    side sides[6]; //variable to hold sides of block; in order: top, bottom, left, right, front, back
    std::string name; //name of the block so i can identify it when its solved and copy the solution with the real-life blocks
    int orientation;    /*an int between 0-23 that corresponds to the block's orientation in space.
                        orientation 0 is the root orientation of the cube which is defined when the
                        block is created in main(). Also, the blocks must follow a rigid order of
                        rotation/orientation change to ensure that each orientation is visited only
                        once (see below). To change the orientation, the ++ operator will be 
                        overloaded for block.
                        */
    void rotateBlock(Axis direction); //function to rotate the block by swapping values in sides[] accordingly depending on axis of rotation
public:
    block(); //default contructor
    block(side *sds, std::string nm); //other constructor that takes an array of sides and a name
    ~block(); //destructor
    side* getSides(); //function to get the array of sides
    block& operator++(); //overload the prefix increment operator to change the orientation of the block to the "next" orientation
};

#endif /* block_h */

/*
 The order of rotation of a block is defined as follows:
        0-3: The block is rotated 4 times about its top-bottom axis
        4-7: The block is rotated once about its left-right axis, then rotated 4 times about its top-bottom axis
        8-11: The block is rotated once more about its left-right axis, then rotated 4 times about its top-bottom axis
        12-15: The block is rotated once more about its left-right axis, then rotated 4 times about its top-bottom axis
        16-19: The block is rotated once more about its left-right axis to return to its root orientation, then once
                about its front-back axis and four times about its top-bottom axis
        20-24: The block is rotated twice more about its front-back axis, and then four times about its top-bottom axis
 
 This can be thought of as putting the top face in each of the six possible positions, and for each of these positions checking all the possible orientations. 
 */
