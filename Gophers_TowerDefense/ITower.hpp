//
//  ITower.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef ITower_hpp
#define ITower_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "IEnemy.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <sys/time.h>

using namespace std;

class ITower {
public:
    ITower(vector<IEnemy*> *, vector<ITower*> *, SDL_Point p);
    ~ITower();
    
    void attack(); // fuction to begin attacking
    
    // get the position of this tower
    SDL_Point getPos();
    // get the range of this tower
    int getRange();
    
    bool inRange(IEnemy *);
    
    
protected:
    int pts_per_kill;
    SDL_Point pos;
    int range;
    int damage;
    int cost;
    int attackDelay; // the interval between attacks
    
    
//  Should be in view
//    SDL_Renderer ** gRenderer; // double pointer to renderer
//    SDL_Texture * gTower; // texture containing tower's image
//    SDL_Rect gTowerRect; // container for gTower texture
//    SDL_Texture * gRange; // texture for Range radius
//    SDL_Rect gRangeRect; // container for Range radius
    
    vector<IEnemy*> *enemies; // ref to vector of addresses of enemies from main.cpp
    vector<ITower*> *towers; // ref to vector of addresses of tower from main.cpp
    
    // is there any enemy in range
    bool anyEnemyInRange();
    
    // Attack the enemy
    virtual void attackHelp() = 0;
    
    // update the enemy list, remove the dead enemy
    void updateEnemyList();
    
    
    
private:
    ITower& operator=(const ITower& i);
    // allows for milliseconds of current time, for attack frequency
    struct timeval timeStruct;
    // last time that an Enemy was attacked
    long long lastAttackTime;
    
    // check whether it is right time to attack
    bool goodToAttack();
    
    // update the attack time, should do it after attack
    void updateAttackTime();
    
    
    // give two SDL_Points, calculate their distance
    double calcDistance(SDL_Point, SDL_Point);

    
};

#endif /* ITower_hpp */
