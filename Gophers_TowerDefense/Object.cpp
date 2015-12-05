//
//  Object.cpp
//  Gophers_TowerDefense
//
//  Created by Chenxi Yuan on 2015/12/5.
//  Copyright © 2015年 RB. All rights reserved.
//

#include "Object.hpp"

using namespace std;

Object::Object(SDL_Renderer ** gRendererPtr) {
    MAX_DIMENSION = 60;
    MAX_DIMENSION = 0.57; // ddecimal of max percentage
    gRenderer = gRendererPtr;
}

/*
 Return an SDL_Rect with an SDL_Surface as the background
 Method assumes a square image is most ideal, as long as it is not too distorted
 Returns an SDL_Rect that has no more than the maximum threshold of distortion
 x and y are the coordinates of the position of the top of the SDL_Rect
 */
SDL_Rect Object::getRect(SDL_Texture * texture, int maxDimension, SDL_Point p) {
    SDL_Rect container;
    
    // get height and width of original image
    int width;
    int height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    double textureWidth = width;
    double textureHeight = height;
    
    // height = maxDimension. Distort up to MAX_DISTORTION
    if (textureHeight > textureWidth) {
        
        // scaling factor to reduce height by
        double factor = textureHeight / maxDimension;
        
        // height cannot exceed max dimension
        textureHeight = maxDimension;
        
        // check if factor will cause width to exceed MAX_DISTORTION
        if (1 - (textureWidth / factor / maxDimension) > MAX_DISTORTION) {
            // set width MAX_DISTORTION threshold
            textureWidth = textureWidth / factor * (1 + MAX_DISTORTION);
        }
        
        container.x = (int) (p.x - (0.5 * maxDimension) + (0.5 * (maxDimension - textureWidth)));
        container.y = (int) (p.y - (0.5 * textureHeight));
        
        
    }
    // width = maxDimenstion. Distort height as necessary
    else {
        // scaling factor to reduce height by
        double factor = textureWidth / maxDimension;
        
        // height cannot exceed max dimension
        textureWidth = maxDimension;
        
        // check if factor will cause width to exceed MAX_DISTORTION
        if (1 - (textureHeight / factor / maxDimension) > MAX_DISTORTION) {
            // set width MAX_DISTORTION threshold
            textureHeight = textureHeight / factor * (1 + MAX_DISTORTION);
        }
        
        container.x = (int) (p.x - (0.5 * textureWidth));
        container.y = (int) (p.y - (0.5 * maxDimension) + (0.5 * (maxDimension - textureHeight)));
        
    }
    
    container.w = (int)textureWidth;
    container.h = (int)textureHeight;
    
    return container;
}

// Return an SDL_Texture for the specified image, print errors appropriately
SDL_Texture * Object::loadTexture(std::string path) {
    
    // the final texture
    SDL_Texture * newTexture = NULL;
    
    //Load image at specified path
    SDL_Surface * loadedSurface = IMG_Load(path.c_str());
    
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( *gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}
    
    
    




















