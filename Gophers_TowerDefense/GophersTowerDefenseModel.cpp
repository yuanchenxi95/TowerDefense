#include "ITowerDefenseModel.hpp"
#include "GophersTowerDefenseModel.hpp"

// init constructor
GophersTowerDefenseModel::GophersTowerDefenseModel() {
    mapGenerator = new MapGenerator();
    
    mapStructure = mapGenerator->getMapOne();
    
    
    waveManager = new WaveManager(mapStructure->getEnemyPath());
    
    towerManager = new TowerManager();
    
    
    
    
}

// destructor
GophersTowerDefenseModel::~GophersTowerDefenseModel() {
    // TODO
}

// returns the current game state
GameState GophersTowerDefenseModel::getGameState() {
    return gameState;
}

// sets the current GameState to the given state
void GophersTowerDefenseModel::setGameState(GameState newState) {
    gameState = newState;
}

// tick the world
void GophersTowerDefenseModel::tick() {
    waveManager->tickAndMove();
    towerManager->tickAndAttack();
}




