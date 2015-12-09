//
//  MapGenerator.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef MapGenerator_hpp
#define MapGenerator_hpp

#include <stdio.h>
#include "MapStructure.hpp"


class MapGenerator {
public:
    MapGenerator();
    ~MapGenerator();
    
    MapStructure* getMapOne();
    
private:
    void putETP(int x, int y);
    
    // clear the list
    void resetTheList();
    
    // list of enemy tile points
    vector<SDL_Point*> * loETP;
    
};

#endif /* MapGenerator_hpp */
