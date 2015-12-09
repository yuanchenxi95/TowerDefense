#include "ITowerDefenseModel.hpp"
#include "GophersTowerDefenseModel.hpp"

// init constructor
GophersTowerDefenseModel::GophersTowerDefenseModel() {
    mapGenerator = new MapGenerator();
    
    mapStructure = mapGenerator->getMapOne();
    
    
    waveManager = new WaveManager(mapStructure->getEnemyPath());
    
    towerManager = new TowerManager();
    
    
    health = 1;
    money = 990;
    
    buildTower(2, 2, TowerType::GUNTOWER);
    buildTower(4, 4, TowerType::FREEZETOWER);
    buildTower(5, 5, TowerType::EXPLOSIVETOWER);
    
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
    int i = waveManager->tickAndMove();
    towerManager->tickAndAttack();
    
    health -= i;
    
    if (health <= 0) {
        setGameState(GameState::GAMEMOVER);
    }
}

// return the board, vector<vector<ITile *> *> *
vector<ITile*> * GophersTowerDefenseModel::getBoard() {
    return mapStructure->getBoard();
}

// return the list of enemies, vector<IEnemy *> *
vector<IEnemy *> * GophersTowerDefenseModel::getEnemies() {
    return waveManager->getEnemies();
}

// return the lsit of towers, vector<ITower *> *
vector<ITower *> * GophersTowerDefenseModel::getTowers() {
    return towerManager->getTowerList();
}


// return the current health
int GophersTowerDefenseModel::getHealth() {
    return health;
}

// return the current money
int GophersTowerDefenseModel::getMoney() {
    return money;
}

// build the tower, return ture if success
bool GophersTowerDefenseModel::buildTower(int r, int c, TowerType towerType) {
    
    ITile * et1 = mapStructure->getTile(r, c);
    
    if (et1 == NULL) {
        return false;
    }
    
    Wave ** wp = waveManager->getWavePointer();
    
    if (et1->getTileType() == TileType::TOWERTILE) {
        if (towerType == TowerType::EXPLOSIVETOWER) {
            ExplosiveTower * e1 = new ExplosiveTower(r, c, wp);
            
            if ((money - e1->getCost()) < 0) {
                return false;
            }
            
            money -= e1->getCost();
            
            TowerTile * etc1 =dynamic_cast<TowerTile *>(et1);
            
            towerManager->addTower(e1, etc1);
            
        } else if (towerType == TowerType::GUNTOWER) {
            GunTower * e1 = new GunTower(r, c, wp);
            
            if ((money - e1->getCost()) < 0) {
                return false;
            }
            
            
            money -= e1->getCost();
            
            TowerTile * etc1 =dynamic_cast<TowerTile *>(et1);
            
            towerManager->addTower(e1, etc1);
            
            
        } else if (towerType == TowerType::FREEZETOWER) {
            FreezeTower * e1 = new FreezeTower(r, c, wp);
            
            if ((money - e1->getCost()) < 0) {
                return false;
            }
            
            money -= e1->getCost();
            
            TowerTile * etc1 =dynamic_cast<TowerTile *>(et1);
            
            towerManager->addTower(e1, etc1);
        }
        
        
        return true;
    }
    
    else {
        return false;
    }
    
}




// get the Tile Size
int GophersTowerDefenseModel::getTileSize() {
    return ITile::TILE_SIZE;
}


