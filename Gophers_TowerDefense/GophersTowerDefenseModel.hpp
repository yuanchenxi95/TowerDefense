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
    
    // return the board, vector<vector<ITile *> *> *
    vector<vector<ITile *> *> * getBoard();
    
    // return the list of enemies, vector<IEnemy *> *
    vector<IEnemy *> * getEnemies();
    
    // return the lsit of towers, vector<ITower *> *
    vector<ITower *> * getTowers();
    
    
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
    
    
    // test
    
    
    
    
    // the tower projectiles field
    // TODO
    
    // the player field
    // TODO
    
};


#endif /* GophersTowerDefenseModel_hpp */
