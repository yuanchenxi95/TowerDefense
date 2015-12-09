//
//  Soldier.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Soldier.hpp"


Soldier::Soldier(int x, int y) : IEnemy(x, y) {
    
    moveInterval = 4;
    
    health = 1000;
    maxHealth = 1000;
    
}


EnemyType Soldier::getEnemyType() {
    return SOLDIER;
}