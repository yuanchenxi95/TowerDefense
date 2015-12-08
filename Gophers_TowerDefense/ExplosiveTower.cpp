//
//  ExplosiveTower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ExplosiveTower.hpp"



ExplosiveTower::ExplosiveTower(vector<IEnemy *> * enemiesTemp,
                               vector<ITower *> * towersTemp,
                               SDL_Point p) : ITower(enemiesTemp, towersTemp, p) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 3.
    
    damage = 20;
    attackDelay = 3;
    range = 50;
    cost = 100;
    
}

void ExplosiveTower::attackHelp() {
    for (int i = 0; i < enemies->size(); i ++) {
        IEnemy * ene = (*enemies)[i];
        
        if (inRange(ene)) {
            
            ene->takeDamage(damage);
                        
            return;
        }
    }
    

    
}