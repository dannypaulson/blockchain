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
                        //clockwise from first side in pair (ie top, left, and front)
enum Sides {top, bottom, left, right, front, back};

class block {
    side sides[6]; //in order: top, bottom, left, right, front, back
    std::string name;
public:
    block();
    block(side *sds, std::string nm);
    ~block();
    side* getSides();
    void rotateBlock(Axis direction); //swap values in sides[] accordingly depending on axis of rotation
};

#endif /* block_h */
