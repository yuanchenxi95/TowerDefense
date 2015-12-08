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

using namespace std;


class Wave {
public:
    
    
protected:
    
    
private:
    map<EnemyTile, EnemyTile> * path;
    vector<IEnemy *> * enemies;
};

#endif /* Wave_hpp */
