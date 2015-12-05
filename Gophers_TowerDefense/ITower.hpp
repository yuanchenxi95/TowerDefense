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

using namespace std;

class ITower {
public:
    ITower(vector<IEnemy*> *, vector<ITower*> *, SDL_Point p);
    ~ITower();
    
    void attack(int*); // fuction to begin attacking
    bool inRange(); // is there any enemy is in the range
    void resetTarget(IEnemy *);
    void handleMouseClick(SDL_Point);
    
    
protected:
    int pts_per_kill;
    int MAX_DIMENSION;
    SDL_Point pos;
    int range;
    int damage;
    int attackDelay; // the interval between attacks
    bool renderRange; // bool flag to display range or not
    
//  Should be in view
//    SDL_Renderer ** gRenderer; // double pointer to renderer
//    SDL_Texture * gTower; // texture containing tower's image
//    SDL_Rect gTowerRect; // container for gTower texture
//    SDL_Texture * gRange; // texture for Range radius
//    SDL_Rect gRangeRect; // container for Range radius
    
    IEnemy * target; // target is a pointer to the targeted enemy
    vector<IEnemy*> *enemies; // ref to vector of addresses of enemies from main.cpp
    vector<ITower*> *towers; // ref to vector of addresses of tower from main.cpp
    
    // give two SDL_Points, calculate their distance
    double calcDistance(SDL_Point, SDL_Point);
    
    
    
private:
    ITower& operator=(const ITower& i);
    double MAX_DISTORTION;
    // allows for milliseconds of current time, for attack frequency
    struct timeval timeStruct;
    // last time that an Enemy was attacked
    long long lastAttackTime;
};

#endif /* ITower_hpp */
