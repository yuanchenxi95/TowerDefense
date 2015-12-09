//
//  IEnemy.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "IEnemy.hpp"



IEnemy::IEnemy(SDL_Point* p)  {
    
    pos->x = p->x;
    pos->y = p->y;
    
    counter = new Counter(&moveInterval);
    
    freezeCounter = new Counter(new int(0));
    
    onBoard = false;
}

// delete allocated memory
IEnemy::~IEnemy() {
    // TO-DO
    delete counter;
    counter = NULL;
    
    
    
}

// move the enemy to the given position
void IEnemy::move(SDL_Point *p) {
  
    // check whether it satisfies the requirement of moving
    if (goodToMove()) {
        moveToThePoint(pos, p);
    }
    
}

// set the rowColumn to the given point
void IEnemy::setPosition(SDL_Point* p) {
    pos = p;
}

// get the position of enemy
SDL_Point* IEnemy::getPos() {
    return pos;
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
    
    
}

// get the moveInterval, if it is in freeze stage, scale the move interval
int IEnemy::getMoveInterval() {
    if (freezeCounter->isCoolDown()) {
        return moveInterval;
    } else {
        return moveIntervalScale * moveInterval;
    }
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
void IEnemy::moveToThePoint(SDL_Point* p1, SDL_Point* p2) {
    if (p2->x > p1->x) {
        p1->x += 1;
    }
    
    if (p2->x < p1->x) {
        p1->x -= 1;
    }
    
    if (p2->y > p1->y) {
        p1->y += 1;
    }
    
    if (p2->y < p1->y) {
        p1->y -= 1;
    }
}






