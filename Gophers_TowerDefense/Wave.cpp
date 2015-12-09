//
//  Wave.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Wave.hpp"

Wave::Wave(EnemyPath * tep, vector<IEnemy *> * tloe) {
    ep = tep;
    loe = tloe;
    
    //spawn every minion in 2000 milliseconds
    spawnCounter = new Counter(new int(2000));
    
    tileOfEnemy = new map<IEnemy*, EnemyTile*>();
    
    for (IEnemy * e : *loe) {
        tileOfEnemy->insert(make_pair(e, tep->getStart()));

    }
    
}

Wave::~Wave() {
    // delete the counter
    delete spawnCounter;
    spawnCounter = NULL;
    
    // clear and delete the map
    tileOfEnemy->clear();
    
    delete tileOfEnemy;
    tileOfEnemy = NULL;
    
    
    // TO-DO
    
    
}


// tick all the enemies' counters and spawnCounter
void Wave::tick() {
    spawnCounter->tick();
    
    for (IEnemy * e : *loe) {
        e->tick();
    }
    
}

// return ture if there is an enemy to be spawned
bool Wave::anyEnemyToSpawn() {
    for (IEnemy * e : *loe) {
        if (!e->isOnBoard()) {
            return true;
        }
    }
    return false;
}

// move and spawn the enemy, return how many enemies reach the end
int Wave::move() {
    
    bool alreadySpawn = false;
    
    
    for (IEnemy * e : *loe) {
        // move the enemy
        if (e->isOnBoard()) {
            if (e->isDead()) {
                cerr << "cannot move the dead enemy" <<endl;
            }
            moveHelp(e);
        }
        // spawn an enemy, set alreadySpawn to false
        else if (!alreadySpawn) {
            alreadySpawn = true;
            spawnEnemy(e);
        }
    }
    
    
    int count = killEndEnemy();
    
    updateList();
    
    return count;
    
}

// update enemy list, remove the dead enemies
void Wave::updateList() {
    for (int i = 0; i < loe->size(); i++) {
        IEnemy * e = loe->at(i);
        if (e->isDead()) {
            removeEnemy(e, i);
            
            // call it recursively
            updateList();
            
            return;
        }
    }
}


// are all the enemies dead
bool Wave::allEnemiesDead() {
    return loe->size() == 0;
}


// get the enemy list
vector<IEnemy *> * Wave::getEnemies() {
    return loe;
}

// remove the enemy in the list and hashmap, delete the enemy
void Wave::removeEnemy(IEnemy * e, int i) {
    
    // set the on board to false
    e->setOnBoard(false);
    
    // erase this enemy from the list
    loe->erase(loe->begin() + i);
    
    // delete this enemy
    delete e;
    e = NULL;
    
    // remove this enemy from hashmap
    tileOfEnemy->erase(e);
}


// move the enemy
void Wave::moveHelp(IEnemy * e) {
    
    EnemyTile * et = tileOfEnemy->find(e)->second;
    
    
    e->move(et->getX(), et->getY());
    
    
    //update the destination tile of the enemy after the moves
    updateDestinationTile(e);
    
    
}

// update the destination tile of the enemy
void Wave::updateDestinationTile(IEnemy * e) {
    
    EnemyTile * et = tileOfEnemy->find(e)->second;
    
    // check if it reaches the position of this tile
    // update the destination of this tile
    if (e->getX() == et->getX() && e->getY() == et->getY()) {
        
        EnemyTile * etNext = ep->getEpMap()->find(et)->second;
        
        tileOfEnemy->insert(make_pair(e, etNext));
    }
}

// kill the enemies that reach the end
int Wave::killEndEnemy() {
    int count = 0;
    for (IEnemy * e : *loe) {
        if (tileOfEnemy->find(e)->second == ep->getEnd()) {
            e->kill();
            count++;
        }
    }
    
    return count;
}

// spawn an enemy on board
void Wave::spawnEnemy(IEnemy * e) {
    if (spawnCounter->isCoolDown()) {
        e->setOnBoard(true);
        spawnCounter->reset();
    }
    
}


