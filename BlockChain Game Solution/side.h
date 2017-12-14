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
    side(); //default constructor
    side(Color c); //other constructor
    ~side(); //destructor
    Color getColor(); //function to get the colour of a side
    void setColor(Color c); //function to set the color of a side
};

#endif /* side_h */
