#include "Coin.h"
#include "Player.h"
#include "../Utils/checkML.h"

// en este caso, podría hacerse sin utilizar el nodo
// porque el objeto no se mueve, es estático
// se moverían inicialmente el collider
Coin::Coin(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    // color
    material.setDiffuseColor(ofColor::yellow);
}

void Coin::receiveCarCollision(Player* car) {
    car->addCoins(5);
    kill();
}
