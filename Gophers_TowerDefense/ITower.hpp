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
    ITower(int x, int y, Wave**);
    ~ITower();
    
    void attack(); // fuction to begin attacking
    
    // get the position of this tower
    int getX();
    
    int getY();
    
    // get the range of this tower
    int getRange();
    
    // get cost
    int getCost();
    
    // tick the counter
    void tick();
    
    virtual TowerType getTowerType() = 0;
    
    
protected:
    // the pos of this tile
    int posX;
    int posY;
    
    int row;
    int column;
    
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
    double calcDistance(int x1, int y1, int x2, int y2);
    
    vector<IEnemy *> * getEnemies();
    
    Wave ** wavePointer;
    
    bool inRange(IEnemy *);
    bool anyEnemyInRange();


    
};

#endif /* ITower_hpp */
