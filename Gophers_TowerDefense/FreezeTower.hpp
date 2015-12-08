//
//  FreezeTower.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef FreezeTower_hpp
#define FreezeTower_hpp

#include <stdio.h>

#include "ITower.hpp"


class FreezeTower : public ITower {
public:
    // constructor
    FreezeTower(vector<IEnemy *> *, vector<ITower *> *, SDL_Point);
protected:
    void attackHelp();
    
private:
    
    void freezeEnemy(IEnemy *);
    
    
};

#endif /* FreezeTower_hpp */
