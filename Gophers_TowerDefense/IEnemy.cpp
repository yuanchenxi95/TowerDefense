//
//  IEnemy.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "IEnemy.hpp"


IEnemy::IEnemy()  {
    
    
    
    
    
    
}

// delete allocated memory
IEnemy::~IEnemy() {
    // TO-DO
    
}


// get the position of enemy
SDL_Point IEnemy::getPos() {
    return pos;
}

// reduce Enemy's health by the given damage
void IEnemy::takeDamage(int damage) {
    health -= damage;
}

// return true if the health is <= 0
bool IEnemy::isDead() {
    return health <= 0;
}

// set the moveInterval
void IEnemy::setMoveInterval(int mi) {
    moveInterval = mi;
}

// get the moveInterval
int IEnemy::getMoveInterval() {
    return moveInterval;
}





