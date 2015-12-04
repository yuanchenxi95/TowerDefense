#ifndef ITowerDefenseView_hpp
#define ITowerDefenseView_hpp

/*
 * Interface for a view for the tower defense game.
 *
 * Should not be possible to instatiate, copy, or assign.  All member functions
 * must be overridden by subclasses.
 */
class ITowerDefenseView {
public:
  
  // destructor
  virtual ~ITowerDefenseView() = 0;
  
  // renders the game view
  virtual void render() = 0;
};



#endif /* ITowerDefenseView_hpp */
