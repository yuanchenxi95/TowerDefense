//
//  Object.hpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>

using namespace std;

class Object {
public:
    Object(SDL_Renderer **gRenderer);
    SDL_Rect getRect(SDL_Texture * texture, int maxDimension, SDL_Point p);
    SDL_Texture* loadTexture(std::string path);
    virtual void render() = 0;
private:
    SDL_Renderer ** gRenderer; // double pointer to renderer
protected:
    int MAX_DIMENSION;
    double MAX_DISTORTION; // decimal of max percentage
};

#endif /* Object_hpp */
