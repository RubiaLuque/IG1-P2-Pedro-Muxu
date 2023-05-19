#include "Barrier.h"
#include "Player.h"
#include "../Utils/checkML.h"

Barrier::Barrier(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim), bTime(0) {
    material.setDiffuseColor(ofColor::darkGrey);
}

void Barrier::update() {
    if (bTime < UPDOWN_TIME) {
        transform.move(transform.getYAxis() * OFFSET * ofGetLastFrameTime());
    }
    else if (bTime >= UPDOWN_TIME) {
        transform.move(transform.getYAxis() * -OFFSET * ofGetLastFrameTime());
    }

    bTime += ofGetLastFrameTime();

    if (bTime >= TOTAL_TIME) {
        bTime = 0;
    }
}

void Barrier::receiveCarCollision(Player* car) {
    car->stop();
}