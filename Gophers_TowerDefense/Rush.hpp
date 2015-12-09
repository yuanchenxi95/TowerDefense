//
//  Rush.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef Rush_hpp
#define Rush_hpp

#include <stdio.h>
#include "IEnemy.hpp"

class Rush : public IEnemy {
public:
    Rush(int x, int y);
    
    EnemyType getEnemyType();
private:
    
    
};
    
    
#endif /* Rush_hpp */
