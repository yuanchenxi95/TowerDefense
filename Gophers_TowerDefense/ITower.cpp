//
//  ITower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ITower.hpp"
#include <iostream>


ITower::ITower(int r, int c, Wave ** w) {
    
    row = r;
    column = c;
    
    posX = row * 60 + 60 / 2;
    posY = column * 60 + 60 / 2;
    wavePointer = w;
    
    counter = new Counter(&attackDelay);
    
}

ITower::~ITower() {
    delete counter;
    counter = NULL;
    
    
}


// get the position of this tower
int ITower::getX() {
    return posX;
}

int ITower::getY() {
    return posY;
}



// get the range of this tower
int ITower::getRange() {
    return range;
}

// get cost
int ITower::getCost() {
    return cost;
}

// tick the counter
void ITower::tick() {
    counter->tick();
}



// attack
void ITower::attack() {
    vector<IEnemy*> * enemies = (*wavePointer)->getEnemies();
    
    // stop the method if it is not good to attack
    if (goodToAttack()) {
        
        attackHelp(enemies);
        
        counter->reset();
    }
    
}

// check whether it is good time to attack
bool ITower::goodToAttack() {
    
    return counter->isCoolDown() && anyEnemyInRange();
    
}




// Is the given enemy in the range of this tower?
bool ITower::inRange(IEnemy * ene) {

    int x1 = getX();
    int y1 = getY();
    
    int x2 = ene->getX();
    int y2 = ene->getY();
    
    int distance = calcDistance(x1, y1, x2, y2);
    
    return distance <= range;
}

// is there any enemy in range
bool ITower::anyEnemyInRange() {
    for (IEnemy * e : *getEnemies()) {
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
double ITower::calcDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));
}


vector<IEnemy *> * ITower::getEnemies() {
    return (*wavePointer)->getEnemies();
}












