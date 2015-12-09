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

// returns the board tiles of this model
ITile** GophersTowerDefenseModel::getBoardTiles() {
    // TODO this is a dummy valu
    return new ITile*[10];
}

// returns the current game state
GameState GophersTowerDefenseModel::getGameState() {
    return gameState;
}

// sets the current GameState to the given state
void GophersTowerDefenseModel::setGameState(GameState newState) {
    gameState = newState;
}

// testing only:
void GophersTowerDefenseModel::toggleShowBackground() {
    isShowBK = !isShowBK;
}

// testing only:
bool GophersTowerDefenseModel::isShowingBackground() const {
    return isShowBK;
}

// tick the world
void GophersTowerDefenseModel::tick() {
    waveManager->tickAndMove();
    towerManager->tickAndAttack();
}




