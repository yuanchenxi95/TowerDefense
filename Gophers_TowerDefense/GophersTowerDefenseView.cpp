#include "GophersTowerDefenseView.hpp"
#include "SDL2/SDL.h"
#include <iostream>

GophersTowerDefenseView::GophersTowerDefenseView(const ITowerDefenseModel & model) {
  tdModel = &model;
  if(!init()) {
    std::cout << "SDL init failed somewhere!" << std::endl;
  } else {
    if(!loadMedia()) {
      std::cout << "Media init failed somewhere!" << std::endl;
    }
  }
}

GophersTowerDefenseView::~GophersTowerDefenseView() {
  // TODO
  tdModel = NULL;         // Does not destroy, model will be destructed in main
  destructAndCloseAll();
}

void GophersTowerDefenseView::render() {
  SDL_FillRect(windowSurface, 0, SDL_MapRGB(windowSurface->format, 0, 0, 0));
//  if (tdModel->isShowingBackground()) {
//    SDL_BlitSurface(backgroundSurface, NULL, windowSurface, NULL);
//  }
  SDL_UpdateWindowSurface(mainFrame);
}

void GophersTowerDefenseView::outputSDLError(std::string prompt) {
  std::cout << prompt << "; SDL_Error: " << SDL_GetError() << std::endl;
}

bool GophersTowerDefenseView::loadMedia() {
  bool hasFailed = false;
  
  backgroundSurface = loadBMPSurface("background.bmp");
    
    // TO-DO
  
  return !hasFailed;
}

SDL_Surface* GophersTowerDefenseView::loadBMPSurface(std::string path) {
  SDL_Surface * imageSurface = SDL_LoadBMP(path.c_str());
  
  if(backgroundSurface == NULL) {
    outputSDLError("Unable to load " + path + "!");
  }
  return imageSurface;
}

bool GophersTowerDefenseView::init() {
  bool hasFailed = false;
  
  // SDL
  if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
    outputSDLError("SDL init failed!");
    hasFailed = true;
  } else {
    // Window
    mainFrame = SDL_CreateWindow("Gophers TowerDefense",
                                 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                 WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (mainFrame == NULL) {
      outputSDLError("Main game window init failed!");
      hasFailed = true;
    } else {
      // Window surface
      windowSurface = SDL_GetWindowSurface(mainFrame);
    }
  }
  
  return !hasFailed;
}

void GophersTowerDefenseView::destructAndCloseAll() {
  SDL_FreeSurface(backgroundSurface);
  backgroundSurface = NULL;
  
  SDL_DestroyWindow(mainFrame);
  mainFrame = NULL;
  
  SDL_Quit();
}



