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
FreezeTower::FreezeTower(SDL_Point p) : ITower(p) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 3000 milliseconds.
    
    damage = 20;
    attackDelay = 1000;
    range = 150;
    cost = 100;

    
}

void FreezeTower::attackHelp(vector<IEnemy*> * enemies){

    if (enemies->size() > 0) {
        (*enemies)[0]->takeDamage(damage);
    }
    
}

void FreezeTower::freezeEnemy(IEnemy * ene) {
    
    int currentMoveInterval = ene->getMoveInterval();
    
    // slow it by half
    ene->setMoveIntervalScale(currentMoveInterval * 2, 3000);
    
}