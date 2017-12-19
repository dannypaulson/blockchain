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
#include <vector>

//define an enum for the axis of rotation of a block
enum Axis {tb, lr, fb};
/*
 tb is top-bottom axis, lr is left-rigth axis, fb is front/back axis
 spin direction is clockwise as seen from first side in pair (ie as seen from top, left, and front)
 */

//define an enum for the sides of the cube
enum Sides {top_, bottom_, left_, right_, front_, back_};

class block {
    //vector to hold sides of block; in order: top, bottom, left, right, front, back
    std::vector<side> sides;
    
    //variable to hold the number of sides of the block (default is 6)
    int numOfSides;
    
    //name of the block so i can identify it when its solved and copy the solution with the real-life blocks
    std::string name;
    
    //an int between 0-23 that corresponds to the block's orientation in space.
    int orientation;
    /*
     orientation 0 is the root orientation of the cube which is defined when the
     block is created in main(). Also, the blocks must follow a rigid order of
     rotation/orientation change to ensure that each orientation is visited only
     once (see below). To change the orientation, the ++ operator will be
     overloaded for block.
     */
    
    //function to rotate the block by swapping values in sides[] accordingly depending on axis of rotation
    void rotateBlock(Axis direction);
    
public:
    //default contructor
    block();
    
    //other constructor that takes an array of sides and a name; 6 sides by default
    block(side *sds, std::string nm);
    
    //initalize all explicitly
    block(side *sds, std::string nm, int n);
    
    //destructor
    ~block();
    
    //function to get the array of sides
    std::vector<side> getSides();
    
    //function to get the block name
    std::string getName();
    
    //function to get the number of sides
    int getNumOfSides();
    
    //overload the prefix increment operator to change the orientation of the block to the "next" orientation
    block& operator++();
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
