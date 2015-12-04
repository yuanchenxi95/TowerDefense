#ifndef IController_hpp
#define IController_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

class IController {
  
public:
  virtual ~IController() = 0;
  
  virtual void handleKey(SDL_Keycode keycode) = 0;
  
protected:
  // TODO put model here
};

#endif /* IController_hpp */
