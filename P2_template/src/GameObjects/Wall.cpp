#include "Wall.h"
#include "Player.h"
#include "../Utils/checkML.h"

Wall::Wall(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    // color
    material.setEmissiveColor(ofColor::darkorange);
}

void  Wall::receiveCarCollision(Player* car) {
    car->stop();
}
