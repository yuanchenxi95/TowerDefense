//
//  TowerManager.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "TowerManager.hpp"


TowerManager::TowerManager() {
    lot = new vector<ITower *>();
    
}




TowerManager::~TowerManager() {
    for (ITower * t : *lot) {
        delete t;
        t =NULL;
    }
    
    delete lot;
    lot = NULL;
    
    
}

// get the tower list
vector<ITower *> * TowerManager::getTowerList() {
    return lot;
}

// tick and attack
void TowerManager::tickAndAttack() {
    for (ITower * t: *lot) {
        t->tick();
        t->attack();
    }
}

