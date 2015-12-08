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
    
}

Wave::~Wave() {
    delete spawnCounter;
    spawnCounter = NULL;
    
}







