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
enum Sides {top, bottom, left, right, front, back};

class block {
    side sides[6]; //variable to hold sides of block; in order: top, bottom, left, right, front, back
    std::string name; //name of the block so i can identify it when its solved and copy the solution with the real-life blocks
public:
    block(); //default contructor
    block(side *sds, std::string nm); //other constructor that takes an array of sides and a name
    ~block(); //destructor
    side* getSides(); //function to get the array of sides
    void rotateBlock(Axis direction); //function to rotate the block by swapping values in sides[] accordingly depending on axis of rotation
};

#endif /* block_h */
