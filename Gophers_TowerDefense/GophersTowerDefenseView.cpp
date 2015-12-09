#include "GophersTowerDefenseView.hpp"
#include "ITowerDefenseModel.hpp"
#include "SDL2/SDL.h"
#include <SDL2_image/SDL_image.h>
#include <iostream>

GophersTowerDefenseView::GophersTowerDefenseView(ITowerDefenseModel & model) {
  tdModel = &model;
  
  WINDOW_WIDTH = 60 * 15;
  WINDOW_HEIGHT = 60 * 10;
  
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

void GophersTowerDefenseView::destructAndCloseAll() {
  
  // Free loaded media:
  
  // Free textures
  SDL_DestroyTexture(texture_gunTower);
  texture_gunTower = NULL;
  SDL_DestroyTexture(texture_freezeTower);
  texture_freezeTower = NULL;
  SDL_DestroyTexture(texture_explosiveTower);
  texture_explosiveTower = NULL;
  
  SDL_DestroyTexture(texture_turtleNormal);
  texture_turtleNormal = NULL;
  SDL_DestroyTexture(texture_turtleFast);
  texture_turtleFast = NULL;
  SDL_DestroyTexture(texture_turtleTank);
  texture_turtleTank = NULL;
  
  // Free surfaces
  SDL_FreeSurface(backgroundSurface);
  backgroundSurface = NULL;
  
  // Destroy renderer then window components
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(mainFrame);
  renderer = NULL;
  mainFrame = NULL;
  
  IMG_Quit();
  SDL_Quit();
}

// =================================================================================================
// RENDERING
// =================================================================================================

// Top-level render function: calls helpers to render the model.
void GophersTowerDefenseView::render() {
  
  // Clear screen
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);
  
  //  SDL_FillRect(windowSurface, 0, SDL_MapRGB(windowSurface->format, 0, 0, 0));
  
  // Render to screen
  for (ITile * tile : *tdModel->getBoard()) {
    SDL_Rect outlineRect =
    // y is column number, x is row number
    {tile->getRow() * cellSize, tile->getColumn() * cellSize, cellSize, cellSize};
//    std::cout << tile->getColumn() << std::endl;
    switch (tile->getTileType()) {
      case ENEMYTILE:
        SDL_SetRenderDrawColor(renderer, 112, 173, 71, 0x00);
        break;
      case TOWERTILE:
        SDL_SetRenderDrawColor(renderer, 217, 217, 217, 0x00);
        break;
    }
    SDL_RenderFillRect(renderer, &outlineRect);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0x00);
    SDL_RenderDrawRect(renderer, &outlineRect);
  }
  
  for (IEnemy * e : *(tdModel->getEnemies())) {
    SDL_Rect rect =
    // y is column number, x is row number
    {e->getX() * cellSize, e->getY() * cellSize, cellSize, cellSize};
    switch (e->getEnemyType()) {
      case SOLDIER:
        SDL_RenderCopy(renderer, texture_turtleNormal, NULL, &rect);
        break;
      case TANK:
        SDL_RenderCopy(renderer, texture_turtleTank, NULL, &rect);
        break;
      case RUSH:
        SDL_RenderCopy(renderer, texture_turtleFast, NULL, &rect);
        break;
    }
  }
  
  // Update
  SDL_RenderPresent(renderer);
}


// =================================================================================================
// LOADING MEDIA
// =================================================================================================

// initializes and loads: all SDL and media rendering objects
bool GophersTowerDefenseView::init() {
  bool hasFailed = false;
  
  // SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    outputSDLError("Failed: init SDL!");
    hasFailed = true;
  } else {
    // Window
    mainFrame = SDL_CreateWindow("Gophers TowerDefense",
                                 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                 WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (mainFrame == NULL) {
      outputSDLError("Failed: init main game window!");
      hasFailed = true;
    } else {
      // init: renderer for window
      renderer = SDL_CreateRenderer(mainFrame, -1, SDL_RENDERER_ACCELERATED);
      if (renderer == NULL) {
        outputSDLError("Failed: init renderer!");
        hasFailed = true;
      } else {
        // set renderer color
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        
        // load: PNG files; window surface must be ready first
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
          outputSDLError("SDL_image could not initialize!");
          hasFailed = true;
        }
      }
    }
  }
  
  return !hasFailed;
}

bool GophersTowerDefenseView::loadMedia() {
  bool hasFailed = false;
  
  backgroundSurface = loadBMPSurface("background.bmp");
  
  
  // Tower textures:
  texture_gunTower = loadTexture("turtleNormalSprite.png");
  texture_freezeTower = loadTexture("turtleNormalSprite.png");;
  texture_explosiveTower = loadTexture("turtleNormalSprite.png");;
  
  // Enemy textures:
  texture_turtleNormal = loadTexture("turtleNormalSprite.png");
  texture_turtleFast = loadTexture("turtleTankSprite.png");
  texture_turtleTank = loadTexture("turtleFastSprite.png");
  
  // TO-DO
  
  return !hasFailed;
}

// returns a loaded SDL_Texture from a given path to a "PNG" file using a an optimized surface
SDL_Texture* GophersTowerDefenseView::loadTexture(std::string path) {
  
  // to return:
  SDL_Texture* newTexture = NULL;
  
  // Load image into regular surface with given path
  SDL_Surface* loadedOptimizedSurface = loadPNGSurface(path);
  
  if(loadedOptimizedSurface == NULL) {
    outputSDLImageError( "Unable to load optimized image surface: " + path + "!");
  } else {
    
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedOptimizedSurface);
    if(newTexture == NULL) {
      outputSDLError("Unable to create texture from optimized image surface!");
    }
  }
  // Free optimized surface
  SDL_FreeSurface(loadedOptimizedSurface);
  
  
  int w, h;
  SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
  std::cout << "new texture has: " << w << " and " << h << std::endl;
  
  
  return newTexture;
}

SDL_Texture * GophersTowerDefenseView::loadTexture(std::string path, int scale) {
  
  // result streched texture
  SDL_Texture * resultScaledTexture = NULL;
  
  // 1. Get optimized image surface
  SDL_Surface * optimizedSurface = loadPNGSurface(path);
  
  // 2. Stretch it
  SDL_Surface * stretchedSurface = NULL;
  SDL_Rect stretchRect;
  stretchRect.x = 0;
  stretchRect.y = 0;
  stretchRect.w = optimizedSurface->w * scale;
  stretchRect.h = optimizedSurface->h * scale;
  SDL_BlitScaled(stretchedSurface, NULL, optimizedSurface, &stretchRect );
  
  // 3. Create texture from stretch result
  resultScaledTexture = SDL_CreateTextureFromSurface(renderer, stretchedSurface);
  if (resultScaledTexture == NULL) {
    outputSDLError("Unable to create texture from optimizedSurface!");
  }
  
  // Free optimized surface
  SDL_FreeSurface(optimizedSurface);
  
  // Free streched surface
  SDL_FreeSurface(stretchedSurface);
  
  int w, h;
  SDL_QueryTexture(resultScaledTexture, NULL, NULL, &w, &h);
  std::cout << "new scaled texture has: " << w << " and " << h << std::endl;
  
  return resultScaledTexture;
}

// returns a loaded SDL_Surface from a given path to a "PNG" file that is optimized
SDL_Surface * GophersTowerDefenseView::loadPNGSurface(std::string path) {
  // 1. Load image into regular surface with given path
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());
  //  SDL_Surface* optimizedSurface = NULL;
  if(loadedSurface == NULL) {
    outputSDLImageError( "Unable to load image: " + path + "!");
  }
  //  else {
  //    // 2. Convert regular surface to screen format optimizedSurface
  //    // Optimized surface used to get the texture:
  //    optimizedSurface = SDL_ConvertSurface(loadedSurface, loadedSurface->format, NULL);
  //    if(optimizedSurface == NULL) {
  //      outputSDLError( "Unable to optimize image: " + path + "!");
  //    }
  //  }
  // Free loaded surface local variable
  //  SDL_FreeSurface(loadedSurface);
  return loadedSurface;
}

// returns a loaded SDL_Surface from a given path to a "BMP" file
SDL_Surface * GophersTowerDefenseView::loadBMPSurface(std::string path) {
  SDL_Surface * imageSurface = SDL_LoadBMP(path.c_str());
  
  if(imageSurface == NULL) {
    outputSDLError("Unable to load " + path + "!");
  }
  return imageSurface;
}

// =================================================================================================
// ERROR RENDERING
// =================================================================================================

void GophersTowerDefenseView::outputSDLError(std::string prompt) {
  std::cout << prompt << "; SDL_Error: " << SDL_GetError() << std::endl;
}

void GophersTowerDefenseView::outputSDLImageError(std::string prompt) {
  std::cout << prompt << "; SDL_Error: " << IMG_GetError() << std::endl;
}