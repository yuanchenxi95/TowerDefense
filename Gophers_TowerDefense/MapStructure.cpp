//
//  MapStructure.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "MapStructure.hpp"



MapStructure::MapStructure(vector<SDL_Point*> * epl, int ro, int cl) {
    
    
    row = ro;
    column = cl;
    enemyPathList = epl;
    
    loET = new vector<EnemyTile*>();
    
    
    board = new vector<ITile *>();
    
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < column; j++) {
            
            if(inList(i, j)) {
                board->push_back(new EnemyTile(i, j));
            } else {
                board->push_back(new TowerTile(i, j));
            }
            
        }
    }
    
    
}

MapStructure::~MapStructure() {
    vector<vector<ITile*> *> * board;
    
    for (vector<ITile *> * lot : *board) {
        for (ITile * t : * lot) {
            delete t;
        }
        
        delete lot;
    }
    
    // delete the board
    delete board;
    
    board = NULL;
    
    // delete the list
    delete enemyPathList;
    
    enemyPathList = NULL;
    
    
    // delete enemypath
    delete enemyPath;
    
    
}

EnemyPath* MapStructure::getEnemyPath() {
    return enemyPath;
}

vector<ITile*> * MapStructure::getBoard() {
    return board;
}

bool MapStructure::inList(int x, int y) {
    for (SDL_Point * p : *enemyPathList) {
        if (p->x == x && p->y == y) {
            return true;
        }
    }
    
    return false;
    
}



