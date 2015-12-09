//
//  Rush.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Rush.hpp"



Rush::Rush(int x, int y) : IEnemy(x, y) {
    
    moveInterval = 2;
    
    health = 500;
    maxHealth = 500;
    
}


Rush::~Rush() {
    delete counter;
    counter = NULL;
}

EnemyType Rush::getEnemyType() {
    return RUSH;
}