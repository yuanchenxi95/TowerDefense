#ifndef Controller_hpp
#define Controller_hpp

#include "IController.hpp"
#include <SDL2/SDL.h>
#include "ITowerDefenseModel.hpp"
#include "ITowerDefenseView.hpp"

class Controller: public IController {
public:
  
  // init constructor
  Controller(ITowerDefenseModel & model, ITowerDefenseView & view);
  
  // destructor
  virtual ~Controller();
  
  // keyhandle
  virtual void handleKey(SDL_Keycode keycode);
  
  // start game loop
  virtual void startLoop();
  
private:
  
  ITowerDefenseModel * tdModel;           // Model to manipulate
  ITowerDefenseView * tdView;             // View to update / render on loops
  SDL_Event eventHandler;                 // game event handler

  
  Controller& operator=(const Controller & other);
  
};

#endif /* Controller_hpp */
