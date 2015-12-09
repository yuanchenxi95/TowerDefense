#ifndef GophersTowerDefenseModel_hpp
#define GophersTowerDefenseModel_hpp

#include <stdio.h>
#include "ITowerDefenseModel.hpp"
#include "Mapstructure.hpp"
#include "Mapgenerator.hpp"
#include "WaveManager.hpp"
#include "TowerManager.hpp"




/*
 * Gophers tower defence model class, a subclass of the ITowerDefenseModel
 *
 */
class GophersTowerDefenseModel: public ITowerDefenseModel {
public:
    // init constructor
    GophersTowerDefenseModel();
    
    // destructor
    virtual ~GophersTowerDefenseModel();
    
    // returns game state
    virtual GameState getGameState();
    
    // sets the current GameState to the given state
    virtual void setGameState(GameState newState);
    
    // testing only:
    virtual void toggleShowBackground();
    
    // testing only:
    virtual bool isShowingBackground() const;
    
    // only for testing
    bool isShowBK = true;
    
    // returns the board tiles of this model
    virtual ITile** getBoardTiles();
    // TODO more methods
    
    // tick the world
    void tick();
    
    
private:
    
    GameState gameState = MENU;         // game loop flag
    
    // the mapGenerator
    MapGenerator * mapGenerator;
    
    // the mapStructure
    MapStructure * mapStructure;
    
    
    // the wave manager
    WaveManager * waveManager;
    
    // the tower manager
    TowerManager * towerManager;
    
    
    
    
    // the tower projectiles field
    // TODO
    
    // the player field
    // TODO
    
};


#endif /* GophersTowerDefenseModel_hpp */
