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
    virtual void handleKey(SDL_Event);
    
    // start game loop
    virtual void startLoop();
    
private:
    
    ITowerDefenseModel * tdModel;           // Model to manipulate
    ITowerDefenseView * tdView;             // View to update / render on loops
    SDL_Event eventHandler;                 // game event handler
    
    int x = -1;
    int y = -1;
    
    bool mouseClick = false;
    
    SDL_Point * p = new SDL_Point();
    
    
    // set the row column according to the position
    void setRowColumn(int x, int y);
    
    
    Controller& operator=(const Controller & other);
    
    
    
};

#endif /* Controller_hpp */
