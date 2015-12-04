#ifndef GophersTowerDefenseModel_hpp
#define GophersTowerDefenseModel_hpp

#include <stdio.h>
#include "ITowerDefenseModel.hpp"



/*
 * Gophers tower defence model class, a subclass of the ITowerDefenseModel
 *
 */
class GophersTowerDefenseModel: public ITowerDefenseModel {
public:
  // init constructor
  GophersTowerDefenseModel();
  
  // destructor
  virtual ~GophersTowerDefenseModel();
  
  // returns game state
  virtual GameState getGameState();
  
  // sets the current GameState to the given state
  virtual void setGameState(GameState newState);
  
  // testing only:
  virtual void toggleShowBackground();
  
  // testing only:
  virtual bool isShowingBackground() const;
  
  // only for testing
  bool isShowBK = true;
  
  // returns the board tiles of this model
  virtual ITile** getBoardTiles();
  // TODO more methods
  

private:
  
  GameState gameState = MENU;         // game loop flag
  
  
  // the board tiles field
  // TODO
  
  // the enemy waves field
  // TODO
  
  // the tower list field
  // TODO
  
  // the tower projectiles field
  // TODO
  
  // the player field
  // TODO

};


#endif /* GophersTowerDefenseModel_hpp */
