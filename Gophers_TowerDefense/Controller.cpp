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
    // delete the pointer
    delete p;
    p = NULL;
    
    tdModel = NULL;         // Model will be deleted in main method, not here.
    tdView = NULL;          // View will be deleted in main method, not here.
    
}

// key handler
void Controller::handleKey(SDL_Event e) {
    while( SDL_PollEvent( &e ) != 0 ) {
        // user request quit
        if (e.type == SDL_QUIT) {
            tdModel->setGameState(GameState::QUIT);
        }
        
        //If mouse click occurs, place image where mouse was clicked
        if(e.type == SDL_MOUSEBUTTONDOWN){
            SDL_GetMouseState(&x,&y);
            
            setRowColumn(x, y);
            
            
           // buildTower(e);
            
            mouseClick = false; 	// reset flag
            break;
        }
        
        if (e.type == SDL_KEYDOWN) {
            
            std::cout << "reach this" << endl;
            switch (e.key.keysym.sym){
                case SDLK_f:
                {
                    tdModel->buildTower(p->x, p->y, TowerType::FREEZETOWER);
                    break;
                }
                case SDLK_e:
                {
                    tdModel->buildTower(p->x, p->y, TowerType::EXPLOSIVETOWER);
                    break;
                }
                case SDLK_g:
                {
                    tdModel->buildTower(p->x, p->y, TowerType::GUNTOWER);
                    break;
                }
                default:;
                    
                    
            }
        }
        
        //        else if(mouseClick) {
        //            // pass x and y mouse click coordinates Towers
        //            // TO-DO
        //
        //            mouseClick = false; 	// reset flag
        //            break;
        //        } else if(e.type == SDL_KEYDOWN) {
        //            mouseClick = false;
        //            break;
        //        }
        //
        
        
    }
}

// game loop
unsigned int lastTime = 0, currentTime;

void Controller::startLoop() {
    // Main loop
    while (tdModel->getGameState() != QUIT) {
        
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1) {
            tdModel->tick();
            tdView->render();
            lastTime = currentTime;
        }
        SDL_Event e;
        handleKey(e);
        
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
        
        
    }
}



void Controller::setRowColumn(int x, int y) {
    int size = tdModel->getTileSize();
    
    int r = (x - size / 2) / size;
    int c = (y - size / 2) / size;
    
    p->x = r;
    p->y = c;
}
