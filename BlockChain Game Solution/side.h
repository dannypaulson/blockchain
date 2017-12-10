//
//  side.h
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#ifndef side_h
#define side_h

enum Color {blue, green, red, white};

class side {
    Color color;
    
public:
    side();
    side(Color c);
    ~side();
    Color getColor();
};

#endif /* side_h */
