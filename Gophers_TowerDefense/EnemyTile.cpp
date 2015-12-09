//
//  EnemyTile.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "EnemyTile.hpp"




// initialize the EnemyTile with the given Point
EnemyTile::EnemyTile(SDL_Point * p) : ITile(p) {
    towerTile = false;
    enemyTile = true;
}

EnemyTile::~EnemyTile() {
    
    // TO-DO: delete SDL_Point
}



// get the Tile type of this tile
TileType EnemyTile::getTileType() {
    return ENEMYTILE;
}