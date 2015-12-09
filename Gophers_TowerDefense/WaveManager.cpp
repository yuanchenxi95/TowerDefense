//
//  WaveManager.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "WaveManager.hpp"


WaveManager::WaveManager(EnemyPath * tep) {
    ep = tep;
    spawnEnemy = false;
    
    wavePointer = & wave;
    
    wave = createNewWave();
}

WaveManager::~WaveManager() {
    ep = NULL;
    
    delete *wavePointer;
    *wavePointer = NULL;
    delete wavePointer;
    wavePointer = NULL;
    
    delete ep;
    
}

// tick all the enemies' counters and spawnCounter
int WaveManager::tickAndMove() {
    if (allEnemiesDead()) {
        wave = createNewWave();
    }
    delete wave;
    
    return (*wavePointer)->move();
}

// get the wave
Wave ** WaveManager::getWavePointer() {
    return wavePointer;
}

// get the enemy list
vector<IEnemy *> * WaveManager::getEnemies() {
    return (*wavePointer)->getEnemies();
}

// are all the enemies dead
bool WaveManager::allEnemiesDead() {
    return (*wavePointer)->allEnemiesDead();
}


// create new Wave
Wave* WaveManager::createNewWave() {
    
    vector<IEnemy*> * loe = new vector<IEnemy*>();
    
    SDL_Point * startPos = ep->getStart()->getPos();
    
    Soldier * s1 = new Soldier(startPos);
    Soldier * s2 = new Soldier(startPos);
    Soldier * s3 = new Soldier(startPos);
    Tank * t1 = new Tank(startPos);
    Rush * r1 = new Rush(startPos);
    
    
    loe->push_back(s1);
    loe->push_back(s2);
    loe->push_back(s3);
    loe->push_back(t1);
    loe->push_back(r1);
    
    
    return new Wave(ep, loe);
    
}

// set the spawnEnemy to the given bool
void WaveManager::setSpawnEnemy(bool b) {
    spawnEnemy = b;
}

// is it good to Spawn
bool WaveManager::goodToSpawn() {
    return wave == NULL && spawnEnemy;
}