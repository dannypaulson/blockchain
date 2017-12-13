//
//  main.cpp
//  BlockChain Game Solution
//
//  Created by Danny Paulson on 2017-11-21.
//  Copyright © 2017 Daniel Paulson. All rights reserved.
//

#include <iostream>
#include "side.h"
#include "block.h"
#include "chain.h"

using namespace std;

int main(int argc, const char * argv[]) {
    /*
	//make blocks based on blocks that exist in real life
    
    //block 0 (start indexing from 0 cause this isnt MATLAB
    side top_0(blue);
    side bottom_0(white);
    side left_0(red);
    side right_0(green);
    side front_0(white);
    side back_0(red);
    
    side sides_0[6] = {top_0, bottom_0, left_0, right_0, front_0, back_0};
    
    block block_0(sides_0, "block 0");
    
    //block 1
    side top_1(red);
    side bottom_1(blue);
    side left_1(red);
    side right_1(red);
    side front_1(white);
    side back_1(green);
    
    side sides_1[6] = {top_1, bottom_1, left_1, right_1, front_1, back_1};
    
    block block_1(sides_1, "block 1");
    
    //block 2
    side top_2(green);
    side bottom_2(white);
    side left_2(blue);
    side right_2(blue);
    side front_2(green);
    side back_2(red);
    
    side sides_2[6] = {top_2, bottom_2, left_2, right_2, front_2, back_2};
    
    block block_2(sides_2, "block 2");
    
    //block 3
    side top_3(green);
    side bottom_3(white);
    side left_3(red);
    side right_3(blue);
    side front_3(blue);
    side back_3(white);
	
	side sides_3[6] = {top_3, bottom_3, left_3, right_3, front_3, back_3 };

	block block_3(sides_3, "block 3");
	*/
	

	// perfect blocks
	side top_0(blue);
	side bottom_0(red);
	side front_0(white);
	side back_0(green);
	side right_0(blue);
	side left_0(blue);

	side sides_0[6] = { top_0, bottom_0, left_0, right_0, front_0, back_0 };

	block block_0(sides_0, "block 0");

	side top_1(red);
	side bottom_1(white);
	side front_1(green);
	side back_1(blue);
	side left_1(blue);
	side right_1(blue);

	side sides_1[6] = { top_1, bottom_1, left_1, right_1, front_1, back_1 };

	block block_1(sides_1, "block 1");

	side top_2(white);
	side bottom_2(green);
	side front_2(blue);
	side back_2(red);
	side left_2(blue);
	side right_2(blue);

	side sides_2[6] = { top_2, bottom_2, left_2, right_2, front_2, back_2 };

	block block_2(sides_2, "block 2");

	side top_3(green);
	side bottom_3(blue);
	side front_3(red);
	side back_3(white);
	side left_3(blue);
	side right_3(blue);

	side sides_3[6] = { top_3, bottom_3, left_3, right_3, front_3, back_3 };

	block block_3(sides_3, "block 3");
	


    //make array of blocks
    block blocks[4] = {block_0, block_1, block_2, block_3};
    
    //make the blockchain!
    chain myChain(blocks);
    
    //solve the blockchain!
    //.......
    cout << "about to solve the blockchain" << endl;
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            
            for (int k = 0; k < 24; k++) {
                
                for (int m = 0; m < 24; m++) {
                    
                    if (myChain.isSolved()) {
                        cout << "Solved" << endl;
						cin.get();
                        return 0;
                    }
                    else {
                        //++(myChain.blocks[0]);
                    }
                    
                }
                //++(myChain.blocks[1]);
                
            }
            //++(myChain.blocks[2]);
            
        }
        //++(myChain.blocks[3]);
    }
    cout << "Not solved" << endl;
	cin.get();
    return 0;
}
