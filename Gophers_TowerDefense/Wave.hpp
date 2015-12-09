//
//  Wave.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef Wave_hpp
#define Wave_hpp

#include <stdio.h>
#include "IEnemy.hpp"
#include "EnemyTile.hpp"
#include <vector>
#include "MapStructure.hpp"
#include "Counter.hpp"
#include <iostream>

using namespace std;


class Wave {
public:
    Wave(EnemyPath *, vector<IEnemy *> *);
    ~Wave();
    
    // tick all the enemies' counters and spawnCounter
    void tick();
    
    // return ture if there is an enemy to be spawned
    bool anyEnemyToSpawn();
    
    // move and spawn the enemy, return how many enemies reach the end
    int move();
    
    // update enemy list, remove the dead enemies
    void updateList();
    
    // are all the enemies dead
    bool allEnemiesDead();
    
    // get the enemy list
    vector<IEnemy *> * getEnemies();
    
    
    
    
protected:
    
    
private:
    
    Counter * spawnCounter;
    
    EnemyPath * ep;
    
    
    vector<IEnemy*> * loe;
    
    map<IEnemy *, EnemyTile *> * tileOfEnemy;
    
    // move the enemy
    void moveHelp(IEnemy *);
    
    // remove the enemy in the list and hashmap, delete the enemy
    void removeEnemy(IEnemy *, int);
    
    // update the destination tile of the enemy
    void updateDestinationTile(IEnemy *);
    
    // kill the enemies that reach the end
    int killEndEnemy();
    
    // spawn an enemy on board
    void spawnEnemy(IEnemy * e);
};

#endif /* Wave_hpp */
