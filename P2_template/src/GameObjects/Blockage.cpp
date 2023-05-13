#include "Blockage.h"
#include "Player.h"
#include "../Utils/checkML.h"

Blockage::Blockage(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {

    material.setDiffuseColor(ofColor::orangeRed);
    collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);
}

Blockage::~Blockage(){}

void Blockage::update() {

}

void Blockage::draw() {
    material.begin();
    {
        collider.draw();
    }
    material.end();
}

void Blockage::drawDebug() {
    collider.drawWireframe();
}

void Blockage::receiveCarCollision(Player* car) {
    car->stop();

}