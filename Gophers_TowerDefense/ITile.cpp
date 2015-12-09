#include "ITile.hpp"
#include <iostream>

ITile::ITile(SDL_Point * rc) {
    rowColumn = new SDL_Point;
    rowColumn->x = rc->x;
    rowColumn->y = rc->y;
    
    pos = new SDL_Point();
    
    pos->x = rowColumn->x * TILE_SIZE + TILE_SIZE / 2;
    pos->y = rowColumn->y * TILE_SIZE + TILE_SIZE / 2;
}

// destructor
ITile::~ITile() {
    delete rowColumn;
    rowColumn = NULL;
    
    delete pos;
    pos = NULL;
}


SDL_Point * ITile::getRowColumn() {
    return rowColumn;
}

SDL_Point * ITile::getPos() {
    
    return pos;
}