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
#include <iostream>
#include <map>
#include "counter.hpp"

class IEnemy {
public:
    
    IEnemy(SDL_Point, SDL_Point); // constructor
    ~IEnemy(); // deconstructor
    
    void move(SDL_Point); // move the enemy to the given position
    void setRowColumn(SDL_Point *); // set the rowColumn to the given point
    void setPosition(SDL_Point *); // set the pos to the given position
    
    SDL_Point getPos(); // return the position of the enemy
    SDL_Point getRowColumn(); // return the row and column of this
    
    void takeDamage(int); // take x amount of damage from an ITower
    bool isDead(); // return true if health is <= 0, false otherwise
    
    void setMoveIntervalScale(int, int); // set the move Interval for how many ticks
    int getMoveInterval(); // get the move Interval
    
    bool isOnBoard(); // is this enemy on board
    void setOnBoard(bool); // set the onBoard to the given boolean
    
protected:
    SDL_Point pos; // the position of the enemy
    SDL_Point rowColumn; // the row and column of this enemy

    int moveInterval; // move every __ milliseconds
    
    long health; // the current health of enemy
    double maxHealth; // the initial health value
    
    // is the enemy good to move
    bool goodToMove();
    
    
private:
    // move the first point to the second point. add 1 to the direction.
    void moveToThePoint(SDL_Point, SDL_Point);
    
    
    Counter * counter;
    
    Counter * freezeCounter;
    
    // the scale of the move interval
    int moveIntervalScale;
    
    bool onBoard;
};

#endif /* IEnemy_hpp */
