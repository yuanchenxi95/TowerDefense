#ifndef IController_hpp
#define IController_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

class IController {
  
public:
  virtual ~IController() = 0;
  
  virtual void handleKey(SDL_Event e) = 0;
  
  virtual void startLoop() = 0;
  
private:
  IController& operator=(const IController & other);
};

#endif /* IController_hpp */
