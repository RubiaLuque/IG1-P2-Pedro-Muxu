#include "Coin.h"
#include "Player.h"
#include "../Utils/checkML.h"

Coin::Coin(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    // color
    material.setDiffuseColor(ofColor::yellow);
    // como no tiene movimiento y se trata de un cubo con color
    // no se utiliza el nodo y se mueve directamente el cubo
    // se podría hacer de la otra manera
    //collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);
}

Coin::~Coin(){
    
}


void Coin::update(){
    
}

void Coin::draw() {
    material.begin();
    {
        collider.draw();
    }
    material.end();
}

void Coin::drawDebug() {
    collider.drawWireframe();
}

void Coin::receiveCarCollision(Player* car) {
    car->addCoins(5);
    kill();
}
