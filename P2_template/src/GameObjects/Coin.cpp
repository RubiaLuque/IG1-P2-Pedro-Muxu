#include "Coin.h"
#include "Player.h"
#include "../Utils/checkML.h"

// en este caso, podría hacerse sin utilizar el nodo
// porque el objeto no se mueve, es estático
// se moverían inicialmente el collider
Coin::Coin(Game* game, glm::vec3 pos, float height, float radius, int coinsToAdd) : GameObject(game, pos, glm::vec3(radius * 2, height, radius * 2)), coinsToAdd(coinsToAdd) {
    // color

    material.setDiffuseColor(ofColor::yellow);

    cylinder.setParent(transform);
    cylinder.set(radius, height);
    cylinder.setResolution(80, 80);

    transform.rotateDeg(90, 1, 0, 0);
}

void Coin::draw() {
    material.begin();
    {
        cylinder.draw();
    }
    material.end();
}

void Coin::update() {
    transform.rotateDeg(SPEED_ROTATION, 0, 1, 0);
}

void Coin::receiveCarCollision(Player* car) {
    car->addCoins(coinsToAdd);
    kill();
}
