//
//  MapStructure.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef MapStructure_hpp
#define MapStructure_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include "EnemyPath.hpp"
#include "ITile.hpp"
#include "EnemyTile.hpp"
#include "TowerTile.hpp"

using namespace std;


// INVARIANT:
// y represents row, x represents column

class MapStructure {
public:
    MapStructure(vector<SDL_Point*> * epl, int cl, int ro);
    ~MapStructure();
    
    
    EnemyPath * getEnemyPath();
    
    vector<vector<ITile*>*> * getBoard();
    
    
private:
    
    // allocate the space of the board
    void initializeBoard();
    
    // set up the enemy tiles and enemyPath
    void setUpEnemyPath();
    
    // set up the tower tiles
    void setUpTowerTiles();
    
    vector<vector<ITile*> *> * board;
    
    vector<SDL_Point*> * enemyPathList;
    
    EnemyPath * enemyPath;
    
    int row;
    int column;
    
    
    
};

#endif /* MapStructure_hpp */
