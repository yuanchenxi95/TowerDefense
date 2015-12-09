//
//  FreezeTower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "FreezeTower.hpp"

// constructor
// slow down enemy
FreezeTower::FreezeTower(int x, int y, Wave ** w) : ITower(x, y, w) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 300 milliseconds.
    
    damage = 20;
    attackDelay = 100;
    range = 200;
    cost = 100;

    
}

void FreezeTower::attackHelp(vector<IEnemy*> * enemies){

    if (enemies->size() > 0) {
        (*enemies)[0]->takeDamage(damage);
        freezeEnemy((*enemies)[0]);
        
    }
    
}

void FreezeTower::freezeEnemy(IEnemy * ene) {
    int cmi = ene->getMoveInterval();
    // slow it by half
    ene->setMoveIntervalScale(3 * cmi, 1000);
    
}

// get the tower type of this tower
TowerType FreezeTower::getTowerType() {
    return FREEZETOWER;
}