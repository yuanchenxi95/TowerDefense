#ifndef ITowerDefenseModel_hpp
#define ITowerDefenseModel_hpp

#include "ITile.hpp"
#include "ITower.hpp"
#include <vector>

// gamestate constants
enum GameState {
    QUIT,
    PLAYING,
    GAMEMOVER,
    MENU
};

/*
 * Interface for a tower defense model
 *
 * Should not be possible to instatiate, copy, or assign.  All member functions
 * must be overridden by subclasses.
 *
 */
class ITowerDefenseModel {
public:
    // destructor
    virtual ~ITowerDefenseModel() = 0;
    
    // returns the current GameState of the model
    virtual GameState getGameState() = 0;

    // sets the current GameState to the given state
    virtual void setGameState(GameState newState) = 0;
    
    // return the board, vector<vector<ITile *> *> *
    virtual vector<ITile *> * getBoard() = 0;
    
    // return the list of enemies, vector<IEnemy *> *
    virtual vector<IEnemy *> * getEnemies() = 0;
    
    // return the lsit of towers, vector<ITower *> *
    virtual vector<ITower *> * getTowers() = 0;
    
    // return the current health
    virtual int getHealth() = 0;
    
    // return the current money
    virtual int getMoney() = 0;
  
    // tick the world
    virtual void tick() = 0;
  
private:
    ITowerDefenseModel& operator=(const ITowerDefenseModel & other);
    
    // Is the given enemy in the range of this tower?
    bool inRange(IEnemy * ene);
    
};

#endif /* ITowerDefenseModel_hpp */
