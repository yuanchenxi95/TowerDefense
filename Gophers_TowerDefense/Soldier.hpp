//
//  Soldier.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef Soldier_hpp
#define Soldier_hpp

#include <stdio.h>
#include "IEnemy.hpp"

class Soldier : public IEnemy {
public:
    Soldier(int x, int y);
    
    EnemyType getEnemyType();
private:
    
};




#endif /* Soldier_hpp */
