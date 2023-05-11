#include "Barrier.h"

#include "Player.h"

Barrier::Barrier(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    material.setDiffuseColor(ofColor::darkGrey);
    collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);
    bTime = 0;
    up = true;
}

Barrier::~Barrier(){}

void Barrier::update() {
    if (bTime < UPDOWN_TIME){
        collider.setPosition(position.x, position.y + OFFSET, position.z);
    }
    else if (bTime >= UPDOWN_TIME) {
        collider.setPosition(position.x, position.y - OFFSET, position.z);
    }

    bTime += ofGetLastFrameTime();

    if (bTime >= TOTAL_TIME) bTime = 0;
}

void Barrier::draw() {
    material.begin();
    {
        collider.draw();
    }
    material.end();
}

void Barrier::drawDebug() {
    collider.drawWireframe();
}

void Barrier::receiveCarCollision(Player* car) {
    car->stop();

}
