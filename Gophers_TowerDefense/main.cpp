#include <iostream>

#include "IController.hpp"
#include "Controller.hpp"

#include "ITowerDefenseModel.hpp"
#include "GophersTowerDefenseModel.hpp"

#include "ITowerDefenseView.hpp"
#include "GophersTowerDefenseView.hpp"

#include "SDL2/SDL.h"

// main method must be in this form for SDL2 framework to function
int main(int argc, char * args[]) {
  
  // Model-View-Controller Pattern
  ITowerDefenseModel * model = NULL;        // Models the entire game
  
  ITowerDefenseView * view = NULL;          // Renders the game from the model
  
  IController * controller = NULL;          // 1. Detects user input;
                                            // 2. Alter model states;
                                            // 3. Renders the view.
                                            // 4. Loop game;

  model = new GophersTowerDefenseModel();
  view = new GophersTowerDefenseView(*model);
  controller = new Controller(*model, *view);
 
  // Initiates the game loop; keeps running until controller detects quit action
  controller->startLoop();

  // Finished running game. Destruct everything bellow
  delete controller;
  controller = NULL;

  delete view;
  view = NULL;

  delete model;
  model = NULL;
  
  return 0;
}
