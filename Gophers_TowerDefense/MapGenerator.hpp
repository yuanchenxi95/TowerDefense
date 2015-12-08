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
#include "ITile.hpp"
#include "EnemyTile.hpp"
#include "TowerTile.hpp"
#include "vector"

class MapGenerator {
public:
    MapGenerator();
    ~MapGenerator();
    
    vector<vector<ITile>> getMapOne();
    
    
    
    
};

#endif /* MapGenerator_hpp */
