#include "Well.h"
#include "Player.h"
#include "../Utils/checkML.h"

Well::Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius_, ofColor color) : GameObject(game, pos, dim) {
    radius = radius_;
    material.setDiffuseColor(color);
}

void Well::draw() {
    material.begin();
    {
        transform.transformGL();
        {
            ofSetCylinderResolution(80, 80);
            ofDrawCylinder(radius, HEIGHT);
        }
        transform.restoreTransformGL();
    }
    material.end();
}

void Well::receiveCarCollision(Player* car) {
    car->fall();
    car->setSpeed(0);
}