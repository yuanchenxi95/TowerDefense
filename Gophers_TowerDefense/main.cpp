#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "IController.hpp"
#include "Controller.hpp"

const int WINDOW_WIDTH = 1200;           // constant window width
const int WINDOW_HEIGHT = 650;           // constant window height

// gamestate constants
enum GameState {
  QUIT,
  PLAYING,
  GAMEMOVER,
  MENU
};
//
//// surface keypress constants
//enum SurfaceKeyPresses {
//  SK_DEFAULT,
//  SK_UP,
//  SK_DOWN,
//  SK_TOTAL
//};

SDL_Window * mainFrame = NULL;
SDL_Surface * windowSurface = NULL;

SDL_Surface * backgroundSurface = NULL;

IController * controller = NULL;

// Init SDL and window
bool init();

// Loads all media
bool loadMedia();

// Destructs all surfaces and media, then closes SDL
void destructAndCloseAll();

// Outputs the last SDL error with given prompt intro
void outputSDLError(std::string prompt);

// Surrounds SDL_LoadBMP with null detection; returns a new surface using a bmp image
SDL_Surface* loadBMPSurface(std::string path);

int main(int argc, char * args[])
{
  controller = new Controller();
  
  if(!init()) {
    std::cout << "SDL init failed somewhere!" << std::endl;
  } else {
    if(!loadMedia()) {
      std::cout << "Media init failed somewhere!" << std::endl;
    } else {
      
      // Main logic
      
      GameState gameState = MENU;         // game loop flag
      SDL_Event eventHandler;             // game event handler
      
      while (gameState != QUIT) {
        
        // 1. Finish responding to all events within event queue
        while (SDL_PollEvent(&eventHandler) != 0) {
          switch (eventHandler.type) {
            case SDL_QUIT:
              gameState = QUIT;
              break;
            case SDL_KEYDOWN:
              controller->handleKey(eventHandler.key.keysym.sym);
              break;
            default:
              break;
          }
        }
        
        // 2. Rendering
        SDL_BlitSurface(backgroundSurface, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface( mainFrame );
        
        
      }
    }
  }
  
  destructAndCloseAll();
  delete controller;
  controller = NULL;
  return 0;
}

void outputSDLError(std::string prompt) {
  std::cout << prompt << "; SDL_Error: " << SDL_GetError() << std::endl;
}

bool init() {
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

bool loadMedia() {
  bool hasFailed = false;
  
  backgroundSurface = loadBMPSurface("background.bmp");
  
  return !hasFailed;
}

SDL_Surface* loadBMPSurface(std::string path) {
  SDL_Surface * imageSurface = SDL_LoadBMP(path.c_str());
  
  if(backgroundSurface == NULL) {
    outputSDLError("Unable to load " + path + "!");
  }
  return imageSurface;
}

void destructAndCloseAll() {
  SDL_FreeSurface(backgroundSurface);
  backgroundSurface = NULL;
  
  SDL_DestroyWindow(mainFrame);
  mainFrame = NULL;
  
  SDL_Quit();
}