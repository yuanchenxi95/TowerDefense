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
    
    IEnemy(SDL_Renderer **gRenderer); // constructor
    ~IEnemy(); // deconstructor
    
    void render(); // Repositions the enemy on the creen after gRenderer is updated
    bool move(); // move the enemy on the screen
    SDL_Point getPos(); // return the position of the enemy
    void takeDamage(int); // take x amount of damage from an ITower
    bool isDead(); // return true if health is <= 0, false otherwise
    
protected:
    int ENEMY_MAX_DIMENSION;
    double MAX_DISTORTION; // decimal of max percentenge
    SDL_Texture * gEnemy; // image of enemy
    SDL_Renderer** gRenderer; // double pointer to renderer
    SDL_Rect enemyRect; // container for enemy image. has position properties
    SDL_Point pos; // the position of the enemy
    struct timeval tp; // allows for milliseconds of current time, for animation
    long long lastMoveTime; // store tiem of last move
    int moveInterval; // move every __ milliseconds
    
    long health; // the current health of enemy
    double maxHealth; // the initial health value
    
    
};

#endif /* IEnemy_hpp */
