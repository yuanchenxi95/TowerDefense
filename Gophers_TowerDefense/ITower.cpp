//
//  ITower.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "ITower.hpp"
#include <iostream>


ITower::ITower(SDL_Renderer ** gRendererPtr, vector<IEnemy*> * enemiesTemp,
               vector<ITower*> *towersTemp) {
    
    
    gRenderer = gRendererPtr;
    enemies = enemiesTemp;
    towers = towersTemp;
    
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
    SDL_DestroyTexture(gTower);
    SDL_DestroyTexture(gRange);
}

// Attack currently targeted enemy. Check if the Tower's attackDelay has been respected first.
// After attacking, check to see if enemy is now dead. If yes, remove the Enemy.
void ITower::attack(int * points) {
    if (target == NULL) {
        return; // no enemy in range
    }
    
    // get current time
    // TO-DO
//    gettimeofday(&timeStruct, NULL);
//    long long curTime = timeStruct.tv_sec * 1000 + timeStruct.tv_usec / 1000;
    
    // if it has been attackDelay amount of time since the last attack, attack
    // TO-DO
    
    // check if enemy died from the msot recent attack
    
    
}


















