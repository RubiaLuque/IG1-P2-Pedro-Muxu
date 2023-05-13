#include "Well.h"
#include "Player.h"
#include "../Utils/checkML.h"

Well::Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius) : GameObject(game, pos) {

    material.setDiffuseColor({ofColor::aliceBlue, 100}); //es invisible
    collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);

    /*circle.setDiffuseColor(ofColor::black);
    circleColl.setPosition(pos);
    circleColl.set(radius * 2, 0, radius * 2);*/
}

Well::~Well() {}

void Well::update() {

}

void Well::draw() {
    material.begin();
    {
        collider.draw();
        drawDebug();
    }
    material.end();
}

void Well::drawDebug() {

}

void Well::recieveCarCollision(Player* car) {
    car->stop();
    onTriggerEnter(car);
}

void Well::onTriggerEnter(Player* car) {
    //activar gravedad sobre coche
    //hacer que caiga por el agujero sobre la carretera
}
