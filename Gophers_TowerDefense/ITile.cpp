#include "ITile.hpp"
#include <iostream>

ITile::ITile(int r, int c) {
    row = r;
    column = c;
    
    posX = row * TILE_SIZE + TILE_SIZE / 2;
    posY = column * TILE_SIZE + TILE_SIZE / 2;
}

// destructor
ITile::~ITile() {

}


int ITile::getRow() {
    return row;
}

int ITile::getColumn() {
    return column;
}

int ITile::getX() {
    return posX;
}

int ITile::getY() {
    return posY;
}