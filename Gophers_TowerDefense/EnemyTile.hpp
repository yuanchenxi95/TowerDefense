//
//  EnemyTile.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef EnemyTile_hpp
#define EnemyTile_hpp

#include <stdio.h>
#include "ITile.hpp"

class EnemyTile :public ITile {
public:
    // initialize the EnemyTile with the given Point
    EnemyTile(SDL_Point p);
    
    // deconstructor
    ~EnemyTile();
    
    // whether this tile is a TowerTile
    bool isTowerTile();
    
    // whether this tile is an enmemy path
    bool isEnemyTile();
    
    // get the position of this tile
    SDL_Point getPos();
    
    
private:
    bool towerTile;
    bool enemyTile;
    
    // the position of this tile
    SDL_Point pos;
};



#endif /* EnemyTile_hpp */
