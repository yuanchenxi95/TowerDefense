#ifndef GophersTowerDefenseView_hpp
#define GophersTowerDefenseView_hpp

#include "ITowerDefenseView.hpp"
#include "ITowerDefenseModel.hpp"
#include <SDL2/SDL.h>
#include <iostream>

/*
 * A graphical view with rendering logic for a tower defense model
 */
class GophersTowerDefenseView: public ITowerDefenseView {
public:
  
  // constructor
  GophersTowerDefenseView(const ITowerDefenseModel & model);
  
  // destructor
  virtual ~GophersTowerDefenseView();
  
  // rendering
  virtual void render();
  
private:
  const ITowerDefenseModel * tdModel;
  
  const int WINDOW_WIDTH = 1200;           // constant window width
  const int WINDOW_HEIGHT = 650;           // constant window height
  
  SDL_Window * mainFrame = NULL;
  SDL_Surface * windowSurface = NULL;
  
  SDL_Surface * backgroundSurface = NULL;
  
  // Outputs the last SDL error with given prompt intro
  void outputSDLError(std::string prompt);
  
  // Init SDL and window
  bool init();
  
  // Surrounds SDL_LoadBMP with null detection; returns a new surface using a bmp image
  SDL_Surface* loadBMPSurface(std::string path);
  
  // Loads all media
  bool loadMedia();
  
  // Destructs all surfaces and media, then closes SDL
  void destructAndCloseAll();
  
};

#endif /* GophersTowerDefenseView_hpp */
