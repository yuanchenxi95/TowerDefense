#ifndef ITile_hpp
#define ITile_hpp

/*
 * Interface for a tile, a smallest component of a board
 *
 * Should not be possible to instatiate, copy, or assign. 
 * All member functions must be overridden by subclasses.
 */

class ITile {
public:
  // destructor
  virtual ~ITile() = 0;
  
private:
  ITile& operator=(const ITile & other);
};

#endif /* ITile_hpp */
