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
FreezeTower::FreezeTower(vector<IEnemy *> * enemiesTemp,
                   vector<ITower *> * towersTemp,
                   SDL_Point p) : ITower(enemiesTemp, towersTemp, p) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 3.
    
    damage = 20;
    attackDelay = 3;
    range = 150;
    cost = 100;
    
}

void FreezeTower::attackHelp(){


    for (int i = 0; i < enemies->size(); i ++) {
        IEnemy * ene = (*enemies)[i];
        
        if (inRange(ene)) {
            
            ene->takeDamage(damage);
            
            freezeEnemy(ene);
            
            return;
        }
    }
    
    
    
}

void FreezeTower::freezeEnemy(IEnemy * ene) {
    
    int currentMoveInterval = ene->getMoveInterval();
    
    // slow it by half
    ene->setMoveInterval(currentMoveInterval * 2);
    
}