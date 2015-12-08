//
//  ExplosiveTower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ExplosiveTower.hpp"



ExplosiveTower::ExplosiveTower(SDL_Point p) : ITower(p) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 3000 milliseconds.
    
    damage = 20;
    attackDelay = 1000;
    range = 50;
    cost = 100;
    

}

void ExplosiveTower::attackHelp(vector<IEnemy*> * enemies) {
    for (int i = 0; i < enemies->size(); i ++) {
        IEnemy * ene = (*enemies)[i];
        
        ene->takeDamage(damage);
        
    }
    
    
    
}