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
    //default constructor
    side();
    
    //other constructor
    side(Color c);
    
    //destructor
    ~side();
    
    //function to get the colour of a side
    Color getColor();
    
    //function to set the color of a side
    void setColor(Color c);
};

#endif /* side_h */
