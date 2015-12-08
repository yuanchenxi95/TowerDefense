//
//  EnemyPath.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef EnemyPath_hpp
#define EnemyPath_hpp

#include <stdio.h>
#include "ITile.hpp"
#include "EnemyTile.hpp"
#include "TowerTile.hpp"
#include <map>
#include <vector>
#include "SDL2/SDL.h"

using namespace std;

class EnemyPath {
public:
    EnemyPath(vector<EnemyTile*> *);
    ~EnemyPath();
    
    //get the start tile of this path
    EnemyTile * getStart();
    
    // get the end tile of this path
    EnemyTile * getEnd();
    
    // get the map of this path
    map<EnemyTile*, EnemyTile*> * getEpMap();
    
    // is the given tile the start tile
    bool isStart(EnemyTile * s);
    
    // is the given tile the end tile
    bool isEnd(EnemyTile * e);
    
private:
    map<EnemyTile*, EnemyTile*> * epMap;
    EnemyTile * start;
    EnemyTile * end;
    
    
    
};

#endif /* EnemyPath_hpp */
