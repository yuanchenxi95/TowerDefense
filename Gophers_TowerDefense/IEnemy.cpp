//
//  IEnemy.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "IEnemy.hpp"



IEnemy::IEnemy(int tx, int ty)  {
    
    x = tx;
    y = ty;
    
    counter = new Counter(&moveInterval);
    
    freezeCounter = new Counter(0);
    
    onBoard = false;
    
    isFreeze = false;
}

// delete allocated memory
// destructor
IEnemy::~IEnemy() { }

// move the enemy to the given position
void IEnemy::move(int tx, int ty) {
  
    
    // check whether it satisfies the requirement of moving
    if (goodToMove()) {
        
//        std::cout << x << " " << y << std::endl;
        moveToThePoint(x, y, tx, ty);
        
        if (isFreeze) {
            counter->set(&moveIntervalScale);
            counter->reset();
        } else {
            counter->set(&moveInterval);
            counter->reset();
        }
        
        if (freezeCounter->isCoolDown()) {
            isFreeze = false;
        }
    }
    
}

// set the rowColumn to the given point
void IEnemy::setPosition(int tx, int ty) {
    x = tx;
    y = ty;
}

// get the position of enemy
int IEnemy::getX() {
    return x;
}

int IEnemy::getY() {
    return y;
}

// reduce Enemy's health by the given damage
void IEnemy::takeDamage(int damage) {
    health -= damage;
}

// return true if the health is <= 0
bool IEnemy::isDead() {
    return health <= 0;
}

// kill this enemy
void IEnemy::kill() {
    health = 0;
}

// set the moveInterval
void IEnemy::setMoveIntervalScale(int scale, int ticks) {
    moveIntervalScale = scale;
    
    isFreeze = true;
    
    freezeCounter = new Counter(&ticks);
    freezeCounter->reset();
    
    
}

// get the moveInterval
int IEnemy::getMoveInterval() {
    return moveInterval;
}

// is this enemy on board
bool IEnemy::isOnBoard() {
    return onBoard;
}

// set the onBoard to the given boolean
void IEnemy::setOnBoard(bool b) {
    onBoard = b;
}

// tick the counters of this enemy
void IEnemy::tick() {
    
    counter->tick();
    freezeCounter->tick();
    
}

// is the enemy good to move
bool IEnemy::goodToMove() {
    
    return counter->isCoolDown();
}

// move the first point to the second point. add unit distance to the direction.
// if on the same spot, don't move
void IEnemy::moveToThePoint(int x1, int y1, int x2, int y2) {
    if (x2 > x1) {
        x += 1;
    }
    
    if (x2 < x1) {
        x -= 1;
    }
    
    if (y2 > y1) {
        y += 1;
    }
    
    if (y2 < y1) {
        y -= 1;
    }
}






