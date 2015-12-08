//
//  IEnemy.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef IEnemy_hpp
#define IEnemy_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include <sys/time.h>

class IEnemy {
public:
    
    IEnemy(); // constructor
    ~IEnemy(); // deconstructor
    
    bool move(); // move the enemy on the screen
    SDL_Point getPos(); // return the position of the enemy
    void takeDamage(int); // take x amount of damage from an ITower
    bool isDead(); // return true if health is <= 0, false otherwise
    
    void setMoveInterval(int); // set the move Interval
    int getMoveInterval(); // get the move Interval
    
    
protected:
    int ENEMY_MAX_DIMENSION;
    double MAX_DISTORTION; // decimal of max percentenge
    SDL_Point pos; // the position of the enemy
    struct timeval tp; // allows for milliseconds of current time, for animation
    long long lastMoveTime; // store tiem of last move
    int moveInterval; // move every __ milliseconds
    
    long health; // the current health of enemy
    double maxHealth; // the initial health value

private:
    
};

#endif /* IEnemy_hpp */
