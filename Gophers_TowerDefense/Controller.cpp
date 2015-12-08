#include "Controller.hpp"
#include "IController.hpp"
#include "ITowerDefenseModel.hpp"
#include <SDL2/SDL.h>

// init constructor
Controller::Controller(ITowerDefenseModel & model, ITowerDefenseView & view) {
  tdModel = &model;
  tdView = &view;
}

// destructor
Controller::~Controller() {
  // TODO
  tdModel = NULL;         // Model will be deleted in main method, not here.
  tdView = NULL;          // View will be deleted in main method, not here.
  
}

// key handler
void Controller::handleKey(SDL_Keycode keycode) {
//  switch (keycode) {
//    case SDLK_UP:
//      std::cout << "up arrow pressed!" << std::endl;
//      tdModel->toggleShowBackground();
//      break;
//  }
}

// game loop
void Controller::startLoop() {
//  // Main loop
//  while (tdModel->getGameState() != QUIT) {
//    
//    // 1. Finish responding to all events within event queue
//    while (SDL_PollEvent(&eventHandler) != 0) {
//      switch (eventHandler.type) {
//        case SDL_QUIT:
//          tdModel->setGameState(QUIT);
//          break;
//        case SDL_KEYDOWN:
//          handleKey(eventHandler.key.keysym.sym);
//          break;
//        default:
//          break;
//      }
//    }
//    
//    tdView->render();
//  }
}