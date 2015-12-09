#include "ITile.hpp"

ITile::ITile(SDL_Point * rc) {
    rowColumn = rc;
    
    pos->x = rowColumn->x * TILE_SIZE + TILE_SIZE / 2;
    pos->y = rowColumn->y * TILE_SIZE + TILE_SIZE / 2;
}

// destructor
ITile::~ITile() { }


SDL_Point * ITile::getRowColumn() {
    return rowColumn;
}

SDL_Point * ITile::getPos() {
    return pos;
}