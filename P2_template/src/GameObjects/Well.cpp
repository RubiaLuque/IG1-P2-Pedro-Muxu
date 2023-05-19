#include "Well.h"
#include "Player.h"
#include "../Utils/checkML.h"

Well::Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius_) : GameObject(game, pos, dim) {
    radius = radius_;
    material.setDiffuseColor({ ofColor::crimson }); 
}

void Well::update() {
    
}

void Well::draw() {
    material.begin();
    {
        transform.transformGL();
        {
            ofDrawCylinder(radius, HEIGHT);
            boxCollider->draw();
        }
        transform.restoreTransformGL();
    }
    material.end();

    //GameObject::draw();
}

void Well::recieveCarCollision(Player* car) {
    car->stop();
    car->fall();
}

