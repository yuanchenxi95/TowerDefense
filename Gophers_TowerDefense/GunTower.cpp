//
//  GunTower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "GunTower.hpp"

// constructor
GunTower::GunTower(int x, int y, Wave * * w) : ITower(x, y, w) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 100 milliseconds.
    
    damage = 50;
    attackDelay = 50;
    range = 300;
    cost = 100;
    
    
    
    
}

// Attack the enemy
void GunTower::attackHelp(vector<IEnemy*> * enemies) {
    if (enemies->size() > 0) {
        (*enemies)[0]->takeDamage(damage);
    }
    
}

// get the tower type of this tower
TowerType GunTower::getTowerType() {
    return GUNTOWER;
}