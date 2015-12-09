#ifndef GophersTowerDefenseView_hpp
#define GophersTowerDefenseView_hpp

#include "ITowerDefenseView.hpp"
#include "ITowerDefenseModel.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
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
  
  // window renderer
  SDL_Renderer * renderer = NULL;
  
  SDL_Window * mainFrame = NULL;
  //  SDL_Surface * windowSurface = NULL;
  
  SDL_Surface * backgroundSurface = NULL;
  
  // Tower textures:
  SDL_Texture * texture_gunTower = NULL;
  SDL_Texture * texture_freezeTower = NULL;
  SDL_Texture * texture_explosiveTower = NULL;
  
  // Enemy textures:
  SDL_Texture * texture_turtleNormal = NULL;
  SDL_Texture * texture_turtleFast = NULL;
  SDL_Texture * texture_turtleTank = NULL;
  
  // Outputs the last SDL error with given prompt intro
  void outputSDLError(std::string prompt);
  
  // Outputs the last SDL error with given prompt intro
  void outputSDLImageError(std::string prompt);
  
  // Init SDL and window
  bool init();
  
  // Surrounds SDL_LoadBMP with null detection; returns a new surface using a bmp image
  SDL_Surface * loadBMPSurface(std::string path);
  
  SDL_Surface * loadPNGSurface(std::string path);
  
  SDL_Texture* loadTexture(std::string path);
  
  SDL_Texture* loadTexture(std::string path, int scale);
  
  // Loads all media
  bool loadMedia();
  
  // Destructs all surfaces and media, then closes SDL
  void destructAndCloseAll();
  
};

#endif /* GophersTowerDefenseView_hpp */
