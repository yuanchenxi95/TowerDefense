//
//  Tank.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef Tank_hpp
#define Tank_hpp

#include <stdio.h>
#include "IEnemy.hpp"

class Tank : public IEnemy {
public:
    Tank(int x, int y);
    
    EnemyType getEnemyType();
    
private:
    
};



#endif /* Tank_hpp */
