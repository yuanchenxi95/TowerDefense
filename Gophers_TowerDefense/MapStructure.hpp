//
//  MapStructure.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef MapStructure_hpp
#define MapStructure_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include "EnemyPath.hpp"
#include "ITile.hpp"

using namespace std;

class MapStructure {
public:
    MapStructure(vector<vector<ITile>>);
    ~MapStructure();
    
    void setEnemyPath(map<ITile, ITile>);
    
    EnemyPath getEnemyPath();
    
    vector<vector<ITile>> getVector();
    
    
private:
    
    vector<vector<ITile>> board;
    
    EnemyPath ep;
    
    
    
};

#endif /* MapStructure_hpp */
