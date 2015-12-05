//
//  TowerTile.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef TowerTile_hpp
#define TowerTile_hpp

#include <stdio.h>
#include "ITile.hpp"
#include "ITower.hpp"

class TowerTile :public ITile {
public:
    // initialize the EnemyTile with the given Point
    TowerTile(SDL_Point p);
    
    // deconstructor
    ~TowerTile();
    
    // whether this tile is a TowerTile
    bool isTowerTile();
    
    // whether this tile is an enmemy path
    bool isEnemyTile();
    
    // get the position of this tile
    SDL_Point getPos();
    
    // is this tile occupied by a tower
    bool isOccupied();
    
    // build the tower
    void buildTower(ITower & t);
    
    
private:
    bool towerTile;
    bool enemyTile;
    
    // is this tile occupied by a tower
    bool occupied;
    
    // the position of this tile
    SDL_Point pos;
    
    // the Tower built on this tile
    // point to Null if ocupied is off
    ITower * tower;
};


#endif /* TowerTile_hpp */
