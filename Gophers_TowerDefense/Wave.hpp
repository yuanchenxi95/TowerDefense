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
#include "EnemyPath.hpp"
#include "Counter.hpp"

using namespace std;


class Wave {
public:
    Wave(EnemyPath *, vector<IEnemy *> *);
    ~Wave();
    
    // tick all the enemies' counters and spawnCounter
    void tick();
    
    // return ture if there is an enemy to be spawned
    bool anyEnemyToSpawn();
    
    // move and spawn the enemy
    void move();
    
protected:
    
    
private:
    
    Counter * spawnCounter;
    
    EnemyPath * ep;
    
    vector<IEnemy*> * loe;
};

#endif /* Wave_hpp */
