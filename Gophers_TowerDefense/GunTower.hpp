//
//  GunTower.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef GunTower_hpp
#define GunTower_hpp

#include <stdio.h>
#include "ITower.hpp"

class GunTower : public ITower {
public:
    // constructor
    GunTower(vector<IEnemy *> *, vector<ITower *> *, SDL_Point);
    
    
private:
    
    
};



#endif /* GunTower_hpp */
