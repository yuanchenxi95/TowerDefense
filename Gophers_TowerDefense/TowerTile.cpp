//
//  TowerTile.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "TowerTile.hpp"


// initialize the EnemyTile with the given Point
TowerTile::TowerTile(int r, int c) : ITile(r, c) {
    towerTile = true;
    enemyTile = false;
    occupied = false;
    
}

TowerTile::~TowerTile() {
    // TO-DO Delete SDL_Point
    delete tower;
    tower = NULL;
}

// get the Tile type of this tile
TileType TowerTile::getTileType() {
    return TOWERTILE;
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