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
  
  // TODO more methdods

private:
  
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
