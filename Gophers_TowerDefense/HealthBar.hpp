//
//  HealthBar.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef HealthBar_hpp
#define HealthBar_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Object.hpp"

class HealthBar : public Object {
public:
    // constructor
    HealthBar(SDL_Renderer ** gRenderer, int maxEnemyDimension);
   
    // deconstructor
    ~HealthBar();
    
    // update key properties of health bar (before rendered)
    void update(SDL_Point p, double proportion);
    
    // render health bar to screen
    void render();
    
    // get rectangle container for health bar
    SDL_Rect getRect(int width, int height);
    
private:
    // double pointer to renderer
    SDL_Renderer ** gRenderer;
    
    // width of health bar
    int barWidth;
    
    // height of health bar
    int barHeight;
    
    // store max dimension of enemy
    int maxEnemyDimension;
    
    SDL_Texture * gGreenBar;
    SDL_Texture * gRedBar;
    
    SDL_Rect greenBarRect;
    SDL_Rect redBarRect;
    
    
    
    
};


#endif /* HealthBar_hpp */
