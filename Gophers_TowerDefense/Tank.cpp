//
//  Tank.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Tank.hpp"


Tank::Tank(int x, int y) : IEnemy(x, y) {
    
    moveInterval = 8;
    
    health = 3000;
    maxHealth = 3000;
    
}

Tank::~Tank() {
    delete counter;
    counter = NULL;
}

EnemyType Tank::getEnemyType() {
    return TANK;
}