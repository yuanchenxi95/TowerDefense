//
//  ITower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ITower.hpp"
#include <iostream>


ITower::ITower(SDL_Point* p, Wave * w) {
    
    pos = p;
    
    enemies = w->getEnemies();
    
    counter = new Counter(&attackDelay);
    
}

ITower::~ITower() {
    delete counter;
    counter = NULL;
    
    
}


// get the position of this tower
SDL_Point* ITower::getPos() {
    return pos;
}


// get the range of this tower
int ITower::getRange() {
    return range;
}

// tick the counter
void ITower::tick() {
    counter->tick();
}



// attack
void ITower::attack(vector<IEnemy*> * enemies) {
    // stop the method if it is not good to attack
    if (goodToAttack()) {
        
        attackHelp(enemies);
        
        counter->reset();
    }
    
}

// check whether it is good time to attack
bool ITower::goodToAttack() {
    
    return counter->isCoolDown() && anyEnemyInRange();
    
//    // get current time
//    gettimeofday(&timeStruct, NULL);
//    long long curTime = timeStruct.tv_sec * 1000 + timeStruct.tv_sec / 1000;
//    
//    // convert attack delay to milliseconds
//    long long attackDelayTime = attackDelay * 1000;
//    
//    // if it has been attackDelay amount of time since the last attack, otherwise hold off
//    return curTime - lastAttackTime >= attackDelayTime;
    
}




// Is the given enemy in the range of this tower?
bool ITower::inRange(IEnemy * ene) {

    SDL_Point * enemy_pos = ene->getPos();
    double distance = calcDistance(enemy_pos, pos);
    return distance <= range;
}

// is there any enemy in range
bool ITower::anyEnemyInRange() {
    for (IEnemy * e : *enemies) {
        if (inRange(e)) {
            return true;
        }
    }

    return false;
}



//// update the enemy list, remove the dead enemy
//void ITower::updateEnemyList() {
//    for (int i = 0; i < enemies->size(); i++) {
//        // find which index in enemy vector the target enemy that just died is
//        if ((*enemies)[i]->isDead()) {
//            // erase pointer from vector
//            enemies->erase(enemies->begin() + i);
//        }
//    }
//}

// give two SDL_Points, calculate their distance
double ITower::calcDistance(SDL_Point * a, SDL_Point * b) {
    return sqrt(pow(a->y - b->y, 2) + pow(a->x - b->x, 2));
}













