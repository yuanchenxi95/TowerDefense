#include "Controller.hpp"
#include "IController.hpp"
#include <SDL2/SDL.h>

// init constructor
Controller::Controller() {
  // TODO
}

// destructor
Controller::~Controller() {
  // TODO
}

// key handler
void Controller::handleKey(SDL_Keycode keycode) {
  switch (keycode) {
    case SDLK_UP:
      std::cout << "up arrow pressed!" << std::endl;
      break;
  }
}