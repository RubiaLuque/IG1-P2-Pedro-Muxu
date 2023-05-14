#include "Barrier.h"
#include "Player.h"
#include "../Utils/checkML.h"

Barrier::Barrier(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setDiffuseColor(ofColor::darkGrey);
    boxCollider->setPosition(pos);
    bTime = 0;
}

void Barrier::update() {
    if (bTime < UPDOWN_TIME) {
        transform.move(0, OFFSET, 0);
        boxCollider->setPosition(transform.getPosition());
    }
    else if (bTime >= UPDOWN_TIME) {
        transform.move(0, -OFFSET, 0);
        boxCollider->setPosition(transform.getPosition());
    }

    bTime += ofGetLastFrameTime();

    if (bTime >= TOTAL_TIME) bTime = 0;
}

void Barrier::draw() {
    material.begin();
    {
        // transform.transformGL();
        boxCollider->draw();
        // drawDebug();
    }
    material.end();
}

void Barrier::receiveCarCollision(Player* car) {
    car->stop();
}