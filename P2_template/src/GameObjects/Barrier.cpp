#include "Barrier.h"
#include "Player.h"
#include "../Utils/checkML.h"

Barrier::Barrier(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    material.setDiffuseColor(ofColor::darkGrey);
    collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);
    bTime = 0;
}

Barrier::~Barrier(){}

void Barrier::update() {
    if (bTime < UPDOWN_TIME){
        transform.move(0, OFFSET, 0);
        collider.setPosition(transform.getPosition());
    }
    else if (bTime >= UPDOWN_TIME) {
        transform.move(0, -OFFSET, 0);
        collider.setPosition(transform.getPosition());
    }

    bTime += ofGetLastFrameTime();

    if (bTime >= TOTAL_TIME) bTime = 0;
}

void Barrier::draw() {

    material.begin();
    {
        transform.transformGL();
        collider.draw();
        drawDebug();
    }
    material.end();
}

void Barrier::drawDebug() {
    collider.drawWireframe();
}

void Barrier::receiveCarCollision(Player* car) {
    car->stop();

}
