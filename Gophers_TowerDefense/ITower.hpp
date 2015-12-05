//
//  ITower.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/4.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef ITower_hpp
#define ITower_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

class ITower {
public:
    virtual ~ITower() = 0;
    
private:
    ITower& operator=(const ITower& i);
};

#endif /* ITower_hpp */
