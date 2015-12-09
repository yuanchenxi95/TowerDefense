//
//  Counter.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/8.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Counter.hpp"


Counter::Counter(int *coolDown) {
    if (coolDown < 0) {
        std::cerr << "counter should not be negative" << std::endl;
    }
    
    coolDownTime = coolDown;
    
    counter = 0;
    
}

Counter::~Counter() {
    coolDownTime = NULL;
}

void Counter::tick() {
    if (counter > 0) {
        counter--;
    }
}

void Counter::reset() {
    counter = *coolDownTime;
}

int* Counter::getCounter() {
    return coolDownTime;
}

bool Counter::isCoolDown() {
    return counter == 0;
}

void Counter::set(int* i) {
    coolDownTime = i;
}