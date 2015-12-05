//
//  HealthBar.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "HealthBar.hpp"
using namespace std;

HealthBar::HealthBar(SDL_Renderer** gRendererPtr, int maxDimension) : Object (gRendererPtr) {
    gRenderer = gRendererPtr;
    maxEnemyDimension = maxDimension;
    barWidth = 45;
    barHeight = 10;
    
    gGreenBar = loadTexture("img/healthGreen.png");
    gRedBar = loadTexture("img/healthRed.png");
    
    greenBarRect = getRect(barWidth, barHeight);
    redBarRect = getRect(0, barHeight);
    
}

HealthBar::~HealthBar() {
    SDL_DestroyTexture(gGreenBar);
    SDL_DestroyTexture(gRedBar);
}

// updates health bar based on proportion of Enemy life left and Enemy's position
void HealthBar::update(SDL_Point p, double proportion) {
    proportion = 1 - proportion;	// given proportion of health remaining, need proportion lost
    
    int offset = 15;
    greenBarRect.x = p.x - .5 * barWidth;
    greenBarRect.y = p.y - offset;
    
    int redBarWidth = proportion * barWidth;
    redBarRect.x = greenBarRect.x + barWidth - redBarWidth;
    redBarRect.y = p.y - offset;
    redBarRect.w = redBarWidth;
}

// render the health bar to the screen
void HealthBar::render() {
    SDL_RenderCopy( *gRenderer, gGreenBar, NULL, &greenBarRect);  // renderings need to be pushed to screen still. happens in main
    SDL_RenderCopy( *gRenderer, gRedBar, NULL, &redBarRect);
}

SDL_Rect HealthBar::getRect(int width, int height) {
    SDL_Rect container;
    
    container.x = 0;	// will be updated before rendered. doesn't matter what value is given
    container.y = 0;
    container.w = width;
    container.h = height;
    return container;
}