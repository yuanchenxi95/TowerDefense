//
//  TowerManager.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef TowerManager_hpp
#define TowerManager_hpp

#include <stdio.h>
#include "GunTower.hpp"
#include "FreezeTower.hpp"
#include "ExplosiveTower.hpp"
#include "TowerTile.hpp"
#include <vector>

class TowerManager {
public:
    TowerManager();
    ~TowerManager();
    
    // get the tower list
    vector<ITower *> * getTowerList();
    
    // tick and attack
    void tickAndAttack();
    
    // add tower to the list
    void addTower(ITower * t, TowerTile * tt);
    
    
protected:
    
    
    
private:
    vector<ITower*> * lot;
    
};


#endif /* TowerManager_hpp */
