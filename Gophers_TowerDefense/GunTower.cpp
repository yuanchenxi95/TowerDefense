//
//  GunTower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "GunTower.hpp"

// constructor
GunTower::GunTower(vector<IEnemy *> * enemiesTemp,
                   vector<ITower *> * towersTemp,
                   SDL_Point p) : ITower(enemiesTemp, towersTemp, p) {
    // initilizes fields
    // deal 100 damage per attack, range is 100, delay is 3.
    
    damage = 100;
    attackDelay = 3;
    range = 180;
    
    
}