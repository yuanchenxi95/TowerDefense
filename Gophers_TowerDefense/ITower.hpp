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
#include "Wave.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include "Counter.hpp"

using namespace std;

// INVARIANT:
// The position tower == the position of the tile contains this tower

// Tower types
enum TowerType {
    GUNTOWER,
    FREEZETOWER,
    EXPLOSIVETOWER
};

class ITower {
public:
    ITower(SDL_Point*, Wave*);
    ~ITower();
    
    void attack(vector<IEnemy*> *); // fuction to begin attacking
    
    // get the position of this tower
    SDL_Point* getPos();
    
    // get the range of this tower
    int getRange();
    
    // tick the counter
    void tick();
    
    virtual TowerType getTowerType() = 0;
    
    
protected:
    // the pos of this tile
    SDL_Point * pos;
    int range;
    int damage;
    int cost;
    
    int attackDelay; // the interval between attacks
    
    // Attack the enemy
    virtual void attackHelp(vector<IEnemy*> *) = 0;
    
    
    Counter * counter;
    
    
    
private:
    ITower& operator=(const ITower& i);
    
    // check whether it is right time to attack
    bool goodToAttack();
    
    // give two SDL_Points, calculate their distance
    double calcDistance(SDL_Point*, SDL_Point*);
    
    vector<IEnemy *> * enemies;
    
    bool inRange(IEnemy *);
    bool anyEnemyInRange();


    
};

#endif /* ITower_hpp */
