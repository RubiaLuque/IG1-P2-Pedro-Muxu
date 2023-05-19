#include "Well.h"
#include "Player.h"
#include "../Utils/checkML.h"

Well::Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius_) : GameObject(game, pos, dim) {
    radius = radius_;
    material.setDiffuseColor(ofColor::crimson);
}

void Well::update() {
    
}

void Well::draw() {
    material.begin();
    {
        transform.transformGL();
        {
            ofDrawCylinder(radius, HEIGHT);
        }
        transform.restoreTransformGL();
    }
    material.end();

    drawDebug();
    //GameObject::draw();
}

void Well::receiveCarCollision(Player* car) {
    car->stop();
    car->fall();
}