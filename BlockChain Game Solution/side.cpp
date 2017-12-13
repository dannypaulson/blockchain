//
//  side.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include <stdio.h>
#include "side.h"

side::side(Color c) {
    color = c;
}

side::side() {
    //color = red;
}

side::~side() {
    
}

Color side::getColor() {
    return color;
}
