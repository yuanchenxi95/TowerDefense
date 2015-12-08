//
//  ITower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ITower.hpp"
#include <iostream>


ITower::ITower(vector<IEnemy*> * enemiesTemp,
               vector<ITower*> *towersTemp, SDL_Point p) {
    
    
    //    gRenderer = gRendererPtr;
    enemies = enemiesTemp;
    towers = towersTemp;
    
    pos = p;

    
    // initialize time so that towers know when they can attack
        gettimeofday(&timeStruct, NULL); // get current time of day
        lastAttackTime = (timeStruct.tv_sec * 1000 + timeStruct.tv_usec / 1000) - (2*attackDelay*1000);   // will make attack eligible immediatley
    
    
    
    
}

ITower::~ITower() {
    
}


// get the position of this tower
SDL_Point ITower::getPos() {
    return pos;
}


// get the range of this tower
int ITower::getRange() {
    return range;
}


// Is the given enemy in the range of this tower?
bool ITower::inRange(IEnemy * ene) {
    
    SDL_Point enemy_pos = ene->getPos();
    double distance = calcDistance(enemy_pos, pos);
    return distance <= range;
}

void ITower::attack() {
    // stop the method if it is not good to attack
    if (goodToAttack()) {
        
        attackHelp();
        
        updateEnemyList();
        updateAttackTime();
    }
    
}

// is there any enemy in range
bool ITower::anyEnemyInRange() {
    for (int i = 0; i < enemies->size(); i ++) {
        if (inRange((*enemies)[i])) {
            return true;
        }
    }
    
    return false;
}



// update the enemy list, remove the dead enemy
void ITower::updateEnemyList() {
    for (int i = 0; i < enemies->size(); i++) {
        // find which index in enemy vector the target enemy that just died is
        if ((*enemies)[i]->isDead()) {
            // erase pointer from vector
            enemies->erase(enemies->begin() + i);
        }
    }
}









// check whether it is good time to attack
bool ITower::goodToAttack() {
    

    
    if (!anyEnemyInRange()) {
        return false;
    }
    
    // get current time
    gettimeofday(&timeStruct, NULL);
    long long curTime = timeStruct.tv_sec * 1000 + timeStruct.tv_sec / 1000;
    
    // convert attack delay to milliseconds
    long long attackDelayTime = attackDelay * 1000;
    
    // if it has been attackDelay amount of time since the last attack, otherwise hold off
    return curTime - lastAttackTime >= attackDelayTime;
    
}


// update the attack time, should do it after attack
void ITower::updateAttackTime() {
    long long curTime = timeStruct.tv_sec * 1000 + timeStruct.tv_sec / 1000;
    
    lastAttackTime = curTime;
}

// give two SDL_Points, calculate their distance
double ITower::calcDistance(SDL_Point a, SDL_Point b) {
    return sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
}










