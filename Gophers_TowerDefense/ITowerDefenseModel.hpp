#ifndef ITowerDefenseModel_hpp
#define ITowerDefenseModel_hpp

#include "ITile.hpp"
#include "ITower.hpp"

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
    
//    // returns the board tiles of this model
//    virtual ITile** getBoardTiles() = 0;
//    
//    // returns the current GameState of the model
//    virtual GameState getGameState() = 0;
//    
//    // sets the current GameState to the given state
//    virtual void setGameState(GameState newState) = 0;
//    
//    // test toggle show background, (testing only temporary)
//    virtual void toggleShowBackground() = 0;
//    
//    // test return show background, (testing only temporary)
//    virtual bool isShowingBackground() const = 0;
    
private:
    ITowerDefenseModel& operator=(const ITowerDefenseModel & other);
    
    // Is the given enemy in the range of this tower?
    bool inRange(IEnemy * ene);
    
};

#endif /* ITowerDefenseModel_hpp */
