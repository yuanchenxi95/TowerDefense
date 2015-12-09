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


// whether this tile is a TowerTile
bool EnemyTile::isTowerTile() {
    return towerTile;
}

// whether this tile is an enmemy path
bool EnemyTile::isEnemyTile() {
    return enemyTile;
}
