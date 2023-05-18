#include "Coin.h"
#include "Player.h"
#include "../Utils/checkML.h"

// en este caso, podr�a hacerse sin utilizar el nodo
// porque el objeto no se mueve, es est�tico
// se mover�an inicialmente el collider
Coin::Coin(Game* game, glm::vec3 pos, glm::vec3 dim, int coinsToAdd) : GameObject(game, pos, dim), coinsToAdd(coinsToAdd) {
    // color
    material.setDiffuseColor(ofColor::yellow);
}

void Coin::receiveCarCollision(Player* car) {
    car->addCoins(coinsToAdd);
    kill();
}
