#include "Blockage.h"
#include "Player.h"
#include "../Utils/checkML.h"

Blockage::Blockage(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::orangeRed);
}

void Blockage::receiveCarCollision(Player* car) {
    car->stop();
}