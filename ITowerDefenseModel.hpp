#ifndef ITowerDefenseModel_hpp
#define ITowerDefenseModel_hpp

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
  
  // returns the board tiles of this model
  // TODO
  
private:
  
};

#endif /* ITowerDefenseModel_hpp */
