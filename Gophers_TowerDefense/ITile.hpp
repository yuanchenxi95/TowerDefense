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
  // destructor
  virtual ~ITile() = 0;

    
    // static ITile* create(SDL_Point p);
    
    // whether this tile is a TowerTile
    virtual bool isTowerTile() = 0;
    
    // whether this tile is an enmemy path
    virtual bool isEnemyTile() = 0;
    
    // get the position of this tile
    virtual SDL_Point getRowColumn();
    
    
    
    
    
protected:
    bool towerTile;
    bool enemyTile;
    
    // the position of this tile
    SDL_Point rowColumn;
    
    
private:
  ITile& operator=(const ITile & other);
    

    
};

#endif /* ITile_hpp */
