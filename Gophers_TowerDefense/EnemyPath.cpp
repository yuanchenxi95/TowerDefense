//
//  EnemyPath.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "EnemyPath.hpp"


EnemyPath::EnemyPath(vector<EnemyTile*> * loET) {
    if (loET->size() == 0) {
        cerr << "enemy tile list cannot be an empty list" << endl;
    }
    
    start = loET->at(0);
    end = loET->at(loET->size() - 1);
    
    
    for (int i = 0; i < loET->size() - 1; i++) {
        epMap->insert(make_pair(loET->at(i), loET->at(i + 1)));
    }
    
}

EnemyPath::~EnemyPath() {
    epMap->clear();
    
    epMap = NULL;
    
    start = NULL;
    
    end = NULL;
}


//get the start tile of this path
EnemyTile * EnemyPath::getStart() {
    return start;
}

// get the end tile of this path
EnemyTile * EnemyPath::getEnd() {
    return end;
}

// get the map of this path
map<EnemyTile*, EnemyTile*> * EnemyPath::getEpMap() {
    return epMap;
}

// is the given tile the start tile
bool EnemyPath::isStart(EnemyTile * s) {
    return s == start;
    
}

// is the given tile the end tile
bool EnemyPath::isEnd(EnemyTile * e) {
    return e == end;
}