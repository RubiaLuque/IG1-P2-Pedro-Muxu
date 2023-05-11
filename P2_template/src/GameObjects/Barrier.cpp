#include "Barrier.h"

#include "Player.h"

Barrier::Barrier(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    material.setDiffuseColor(ofColor::darkGrey);
    collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);
    
    offset = 20;
    up = true;
}

Barrier::~Barrier(){}

void Barrier::update() {
    if (up) {
        collider.setPosition(position.x, position.y + offset, position.z);
        if (position.y > 2000)
            !up;
    }
    else if (!up) {
        collider.setPosition(position.x, position.y - offset, position.z);
        if (position.y < 0)
            up;
    }
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
