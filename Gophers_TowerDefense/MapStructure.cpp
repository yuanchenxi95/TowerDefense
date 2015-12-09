//
//  MapStructure.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "MapStructure.hpp"



MapStructure::MapStructure(vector<SDL_Point*> * epl, int cl, int ro) {
    
    
    row = ro;
    column = cl;
    enemyPathList = epl;
    
    initializeBoard();
    setUpEnemyPath();
    setUpTowerTiles();
    
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

vector<vector<ITile*>*> * MapStructure::getBoard() {
    return board;
}


// allocate the space of the board.
void MapStructure::initializeBoard() {
    board = new vector<vector<ITile*>*>(column);
    
    for(int i = 0; i < column; i++) {
        board->push_back(new vector<ITile*>(row));
    }
    
}

// set up the enemy tiles and the enemy path
void MapStructure::setUpEnemyPath() {
    
    vector<EnemyTile*> * loET = new vector<EnemyTile*>(enemyPathList->size());
    
    for (SDL_Point * p: *enemyPathList) {
        // check enemyPathList
        if (p->y >= row && p->y < 0 && p->x >= column && p->x < 0) {
            cerr << " Illegal coordinate for Enemy Tower" << endl;
        }
        
        EnemyTile * et = new EnemyTile(p);
        
        // change the correspond TowerTile to EnemyTile
        (*(*board)[p->x])[p->y] = et;
        
        loET->push_back(et);
    }
    
    enemyPath = new EnemyPath(loET);
    
}


// set up the tower tiles
void MapStructure::setUpTowerTiles() {
    
    
    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++) {
            
            // if this space does not have a tile, build a tower tile
            if ((*(*board)[i])[j] == NULL) {
                
                SDL_Point * p;
                p->x = i;
                p->y = j;
                
                //board->at(i)->push_back(new TowerTile(p));
                (*(*board)[i])[j] = new TowerTile(p);
            
            }
        }
    }
    
}


