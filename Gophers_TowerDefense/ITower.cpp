//
//  ITower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ITower.hpp"
#include <iostream>


ITower::ITower(SDL_Point p) {
    
    rowColumn = p;
    
    counter = new Counter(&attackDelay);
    
}

ITower::~ITower() {
    delete counter;
    counter = NULL;
    
    
}


// get the position of this tower
SDL_Point ITower::getRowColumn() {
    return rowColumn;
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
    
    return counter->isCoolDown();
    
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











