//
//  TowerTile.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "TowerTile.hpp"


// initialize the EnemyTile with the given Point
TowerTile::TowerTile(SDL_Point p) {
    pos = p;
    towerTile = true;
    enemyTile = false;
    occupied = false;
    
}


// whether this tile is a TowerTile
bool TowerTile::isTowerTile() {
    return towerTile;
}

// whether this tile is an enmemy path
bool TowerTile::isEnemyTile() {
    return enemyTile;
}

// get the position of this tile
SDL_Point TowerTile::getPos() {
    return pos;
}

// is this tile occupied
bool TowerTile::isOccupied() {
    return occupied;
}

// void build the Tower
void TowerTile::buildTower(ITower & t) {
    if (!isOccupied()) {
        tower = &t;
        occupied = true;
    }
}