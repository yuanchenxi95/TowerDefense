//
//  WaveManager.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef WaveManager_hpp
#define WaveManager_hpp

#include "wave.hpp"
#include "Soldier.hpp"
#include "Rush.hpp"
#include "Tank.hpp"


class WaveManager {
public:
    WaveManager(EnemyPath *);
    ~WaveManager();
    
    // tick all the enemies' counters and spawnCounter
    // return how many enemies reach the base
    int tickAndMove();
    
    // get the wave
    Wave ** getWavePointer();
    
    // get the enemy list
    vector<IEnemy *> * getEnemies();
    
    // are all the enemies dead
    bool allEnemiesDead();
    
    // create new Wave
    Wave * createNewWave();
    
    // get the wave number
    int getWaveNumber();
    
    
protected:
    // set the spawnEnemy to the given bool
    void setSpawnEnemy(bool);
    
    // is it good to Spawn
    bool goodToSpawn();
    
private:
    
    Wave ** wavePointer;
    Wave * wave;
    bool spawnEnemy;
    EnemyPath * ep;
    int count = 0;
    
    
    
};


#endif /* WaveManager_hpp */
