//
//  GunTower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "GunTower.hpp"

// constructor
GunTower::GunTower(SDL_Point* p) : ITower(p) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 3000 milliseconds.
    
    damage = 100;
    attackDelay = 1000;
    range = 180;
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