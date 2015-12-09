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

enum EnemyType {
    RUSH,
    TANK,
    SOLDIER
};

class IEnemy {
public:
    
    IEnemy(int x, int y); // constructor
    ~IEnemy(); // deconstructor
    
    void move(int, int); // move the enemy to the given position
    void setPosition(int, int); // set the pos to the given position
    
    // return the position of the enemy
    int getX();
    int getY();
    
    void takeDamage(int); // take x amount of damage from an ITower
    bool isDead(); // return true if health is <= 0, false otherwise
    void kill(); // kill this enemy
    
    void setMoveIntervalScale(int, int); // set the move Interval for how many ticks
    int getMoveInterval(); // get the move Interval
    
    bool isOnBoard(); // is this enemy on board
    void setOnBoard(bool); // set the onBoard to the given boolean
    
    void tick();// tick this enemy's counters
    
    virtual EnemyType getEnemyType() = 0;

    
protected:
    // the position of the enemy
    int x;
    int y;
    
    int moveInterval; // move every __ milliseconds
    
    long health; // the current health of enemy
    double maxHealth; // the initial health value
    
    // is the enemy good to move
    bool goodToMove();
    
    
private:
    // move the first point to the second point. add 1 to the direction.
    void moveToThePoint(int, int, int, int);
    
    
    Counter * counter;
    
    Counter * freezeCounter;
    
    // the scale of the move interval
    int moveIntervalScale = 1;
    
    bool onBoard;
    
    bool isFreeze;
    
    
};

#endif /* IEnemy_hpp */
