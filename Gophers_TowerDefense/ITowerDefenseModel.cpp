#include "ITowerDefenseModel.hpp"

// destructor
ITowerDefenseModel::~ITowerDefenseModel() { }

//
//// Is the given enemy in the range of this tower?
//bool ITowerDefenseModel::inRange(IEnemy * ene) {
//    
//    SDL_Point enemy_pos = ene->getPos();
//    double distance = calcDistance(enemy_pos, rowColumn);
//    return distance <= range;
//}
//
//// is there any enemy in range
//bool ITower::anyEnemyInRange() {
//    for (int i = 0; i < enemies->size(); i ++) {
//        if (inRange((*enemies)[i])) {
//            return true;
//        }
//    }
//    
//    return false;
//}
//
//
//
//// update the enemy list, remove the dead enemy
//void ITower::updateEnemyList() {
//    for (int i = 0; i < enemies->size(); i++) {
//        // find which index in enemy vector the target enemy that just died is
//        if ((*enemies)[i]->isDead()) {
//            // erase pointer from vector
//            enemies->erase(enemies->begin() + i);
//        }
//    }
//}
//
//// give two SDL_Points, calculate their distance
//double ITower::calcDistance(SDL_Point a, SDL_Point b) {
//    return sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
//}
//
