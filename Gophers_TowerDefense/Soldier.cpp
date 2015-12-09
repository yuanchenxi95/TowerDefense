//
//  Soldier.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Soldier.hpp"


Soldier::Soldier(SDL_Point * p) : IEnemy(p) {
    
    moveInterval = 10;
    
    health = 2000;
    maxHealth = 2000;
    
}


EnemyType Soldier::getEnemyType() {
    return SOLDIER;
}