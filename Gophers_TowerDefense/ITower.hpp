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
#include "Counter.hpp"

using namespace std;

// INVARIANT:
// The position tower == the position of the tile contains this tower

class ITower {
public:
    ITower(SDL_Point);
    ~ITower();
    
    void attack(vector<IEnemy*> *); // fuction to begin attacking
    
    // get the position of this tower
    SDL_Point getRowColumn();
    
    // get the range of this tower
    int getRange();
    
    // tick the counter
    void tick();
    
    
protected:
    // thw row and column of this tower
    SDL_Point rowColumn;
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
    double calcDistance(SDL_Point, SDL_Point);


    
};

#endif /* ITower_hpp */
