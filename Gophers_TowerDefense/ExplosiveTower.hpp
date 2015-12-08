//
//  ExplosiveTower.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef ExplosiveTower_hpp
#define ExplosiveTower_hpp

#include <stdio.h>
#include "ITower.hpp"

class ExplosiveTower : ITower {
public:
    ExplosiveTower(vector<IEnemy *> *, vector<ITower *> *, SDL_Point);
    
protected:
    void attackHelp();
    
    
private:
    
    
};

#endif /* ExplosiveTower_hpp */
