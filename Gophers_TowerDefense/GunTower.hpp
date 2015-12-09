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
    GunTower(SDL_Point*);
    
    // get the tower type of this tower
    TowerType getTowerType();
    
    
protected:
    void attackHelp(vector<IEnemy*> *);
    
private:
    
    
};



#endif /* GunTower_hpp */
