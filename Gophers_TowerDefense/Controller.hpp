#ifndef Controller_hpp
#define Controller_hpp

#include "IController.hpp"
#include <SDL2/SDL.h>

class Controller: public IController {
public:
  
  // init constructor
  Controller();
  
  // destructor
  virtual ~Controller();
  
  // keyhandle
  virtual void handleKey(SDL_Keycode keycode);
};

#endif /* Controller_hpp */
