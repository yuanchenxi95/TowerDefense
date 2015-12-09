#ifndef ITile_hpp
#define ITile_hpp

/*
 * Interface for a tile, a smallest component of a board
 *
 * Should not be possible to instatiate, copy, or assign.
 * All member functions must be overridden by subclasses.
 */

#include "SDL2/SDL.h"

class ITile {
public:
    
    ITile(SDL_Point *);
    // destructor
    virtual ~ITile() = 0;
    
    
    // static ITile* create(SDL_Point p);
    
    // whether this tile is a TowerTile
    virtual bool isTowerTile() = 0;
    
    // whether this tile is an enmemy path
    virtual bool isEnemyTile() = 0;
    
    // get the position of this tile
    SDL_Point* getRowColumn();
    
    // get the position of this tile
    SDL_Point* getPos();
    
    // The size of this tile
    static const int TILE_SIZE = 100;
    
    
    
protected:
    bool towerTile;
    bool enemyTile;
    
    // the row and column of this tile
    SDL_Point * rowColumn;
    
    // the position of this tile
    SDL_Point * pos;
    
    
private:
    ITile& operator=(const ITile & other);
    
    
    
};

#endif /* ITile_hpp */
