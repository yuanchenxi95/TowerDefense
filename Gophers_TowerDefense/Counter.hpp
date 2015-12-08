//
//  Counter.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef Counter_hpp
#define Counter_hpp

#include <stdio.h>
#include <iostream>

class Counter {
public:
    Counter(int *);
    ~Counter();
    
    // if counter > 0, sub 1 to the counter. otherwise, do nothing
    void tick();
    
    // reset the counter to the default number.
    void reset();
    
    // get the counter
    int getCounter();
    
    // is it cool down
    bool isCoolDown();
    
private:
    int counter;
    int * coolDownTime;
};

#endif /* Counter_hpp */
