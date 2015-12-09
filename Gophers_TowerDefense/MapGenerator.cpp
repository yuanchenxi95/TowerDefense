//
//  MapGenerator.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "MapGenerator.hpp"

MapGenerator::MapGenerator() {
    loETP = new vector<SDL_Point*>;
}

MapGenerator::~MapGenerator() {
    delete loETP;
    loETP = NULL;
}

MapStructure * MapGenerator::getMapOne() {
    resetTheList();
    
    putETP(0, 1);
    putETP(1, 1);
    putETP(2, 1);
    putETP(3, 1);
    putETP(3, 2);
    putETP(3, 3);
    putETP(3, 4);
    putETP(2, 4);
    putETP(1, 4);
    putETP(1, 5);
    putETP(1, 6);
    putETP(1, 7);
    putETP(2, 7);
    putETP(3, 7);
    putETP(4, 7);
    putETP(5, 7);
    putETP(6, 7);
    putETP(7, 7);
    putETP(7, 6);
    putETP(7, 5);
    putETP(7, 4);
    putETP(7, 3);
    putETP(7, 2);
    putETP(7, 1);
    putETP(8, 1);
    putETP(9, 1);
    putETP(10, 1);
    putETP(11, 1);
    putETP(12, 1);
    putETP(13, 1);
    putETP(13, 2);
    putETP(13, 3);
    putETP(13, 4);
    putETP(12, 4);
    putETP(11, 4);
    putETP(10, 4);
    putETP(10, 5);
    putETP(10, 6);
    putETP(10, 7);
    putETP(10, 8);
    putETP(11, 8);
    putETP(12, 8);
    putETP(13, 8);
    
    /*
     
        0   1   2   3   4   5   6   7   8   9   10  11  12  13  14
    
     0  -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
     
     1  *   +   +   +   -   -   -   +   +   +   +   +   +   +   -
     
     2  -   -   -   +   -   -   -   +   -   -   -   -   -   +   -
     
     3  -   -   -   +   -   -   -   +   -   -   -   -   -   +   -
     
     4  -   +   +   +   -   -   -   +   -   -   +   +   +   +   -
     
     5  -   +   -   -   -   -   -   +   -   -   +   -   -   -   -
     
     6  -   +   -   -   -   -   -   +   -   -   +   -   -   -   -
     
     7  -   +   +   +   +   +   +   +   -   -   +   -   -   -   -
     
     8  -   -   -   -   -   -   -   -   -   -   +   +   +   =   -
     
     9  -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
     
     
     
     */
    
    return new MapStructure(loETP, 15, 10);
    
    
    
    
}

void MapGenerator::putETP(int x, int y) {
    SDL_Point * p = new SDL_Point();
    p->x = x;
    p->y = y;
    loETP->push_back(p);
}

// clear the SDL_Points list
void MapGenerator::resetTheList() {
    delete loETP;
    
    loETP = new vector<SDL_Point*>;
    
}

