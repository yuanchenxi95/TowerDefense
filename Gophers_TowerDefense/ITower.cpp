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
    
    MAX_DIMENSION = 70;
    // MAX_DISTORTION = 0.57;
    target = NULL;
    pts_per_kill = 30;
    renderRange = false;
    
    // initialize time so that towers know when they can attack
//    gettimeofday(&UtimeStruct, NULL); // get current time of day
//    lastAttackTime = (timeStruct.tv_sec * 1000 + timeStruct.tv_usec / 1000) - (2*attackDelay*1000);   // will make attack eligible immediatley
    
    
    
    
}

ITower::~ITower() {
//    SDL_DestroyTexture(gTower);
//    SDL_DestroyTexture(gRange);
}

/* Find an enemy that is in range of the tower
 * If the tower already has a target, check and see if that target is still in range. If not, look for another.
 * If the tower does not have a target, check and see if each enemy in the vector of pointers to
 * Enemies are in range. Set the first one that is as the target.
 * Returns true if it has a target, false if not
 */
bool ITower::inRange() {
    // if there is a target selected, check if it is still in range.
    // if not, reset target
    if (target != NULL) {
        double distance = calcDistance(target->getPos(), pos);
        if (distance <= range) {
            // return true if already locked onto enemy && the enemy is still in range
            return true;
        } else {
            target = NULL;
        }
                               
    }
    
    // if there is no target currently selected, check to see if any of the enemies are in range
    for (int i = 0; i < enemies->size(); i++) {
        SDL_Point enemy_pos = (*enemies)[i]->getPos();
        double distance = calcDistance(enemy_pos, pos);
        if (distance <= range) {
            target = (*enemies)[i];
            return true;
        }
    }
    
    // no target selected
    target = NULL;
    
    return false;
}


// Attack currently targeted enemy. Check if the Tower's attackDelay has been respected first.
// After attacking, check to see if enemy is now dead. If yes, remove the Enemy.
void ITower::attack(int * points) {
    if (target == NULL) {
        return; // no enemy in range
    }
    
    // get current time
    gettimeofday(&timeStruct, NULL);
    long long curTime = timeStruct.tv_sec * 1000 + timeStruct.tv_sec / 1000;
    
    // convert attack delay to milliseconds
    long long attackDelayTime = attackDelay * 1000;
    
    // if it has been attackDelay amount of time since the last attack, otherwise hold off
    if (curTime - lastAttackTime >= attackDelayTime) {
        target->takeDamage(damage);
        lastAttackTime = curTime;
        
        // check if enemy died from the most recent attack
        if (target->isDead()) {
            // if the enemy was just killed by the most recent attack
            *points += pts_per_kill;
            for (int i = 0; i < towers->size(); i++) {
                if ((*towers)[i] != (this)) {
                    (*towers)[i]->resetTarget(target);
                }
                
            }
            
            for (int i = 0; i < enemies->size(); i++) {
                // find which index in enemy vector the target enemy that just died is
                if ((*enemies)[i] == target) {
                    // erase pointer from vector
                    enemies->erase(enemies->begin() + i);
                    // free Enemy's memor
                    delete target;
                    break;
                }
            }
            target = NULL;
        }
        
    }
    
    
}

/*
 If the Tower's target matches the argument, the target should be reset to null
 this method should be used if an enemy was just killed by a tower, meaning 
 other towers should stop trying to attack the dead enemy
 */
void ITower::resetTarget(IEnemy * enemy) {
    if (target == enemy) {
        // reset the Tower's target since it's target is now dead
        target = NULL;
    }
}

void ITower::handleMouseClick(SDL_Point p) {
    // TO-DO
}


// give two SDL_Points, calculate their distance
double ITower::calcDistance(SDL_Point a, SDL_Point b) {
    return sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
}


















