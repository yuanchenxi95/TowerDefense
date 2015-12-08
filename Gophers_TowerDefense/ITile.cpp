#include "ITile.hpp"

// destructor
ITile::~ITile() { }


SDL_Point ITile::getRowColumn() {
    return rowColumn;
}