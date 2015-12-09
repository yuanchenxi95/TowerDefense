#ifndef ITile_hpp
#define ITile_hpp

/*
 * Interface for a tile, a smallest component of a board
 *
 * Should not be possible to instatiate, copy, or assign.
 * All member functions must be overridden by subclasses.
 */

#include "SDL2/SDL.h"

enum TileType {
    ENEMYTILE,
    TOWERTILE
};

class ITile {
public:
    
    ITile(int r, int c);
    // destructor
    virtual ~ITile() = 0;
    
    
    // static ITile* create(SDL_Point p);
    
    // get the position of this tile
    int getRow();
    
    int getColumn();
    
    // get the position of this tile
    int getX();
    int getY();
    
    // get the Tile type of this tile
    virtual TileType getTileType() = 0;
    
    // The size of this tile
    static const int TILE_SIZE = 60;
    
    
    
protected:
    bool towerTile;
    bool enemyTile;
    
    // the row and column of this tile
    int row;
    int column;
    
    // the position of this tile
    int posX;
    int posY;
    
    
private:
    ITile& operator=(const ITile & other);
    
    
    
};

#endif /* ITile_hpp */
