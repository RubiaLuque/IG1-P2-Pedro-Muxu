#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"

Player::Player(Game* game) :GameObject(game, glm::vec3(0, 0, 0)),
speed(0), bLight(false), coins(0) {
    // usando el material se le da un color al objeto
    material.setDiffuseColor(ofColor::blue);

    // todos los objetos se mueven a partir de su nodo
    // se hace que el faro se hija de un nodo
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    // mover el faro
    faro.move(0, 0, 50);
    // rotarlo
    faro.rotateDeg(-200, 1, 0, 0);

    // cambiar el tamaño del objeto
    collider.set(100);
}

Player::~Player() {}

void Player::update(){
    prevPos = transform.getPosition();
    transform.move(transform.getZAxis() * speed);
    
    if (speed > MAX_SPEED) {
        speed = MAX_SPEED;
    }
    else if (speed < 0) {
        speed = 0;
    }
}

void Player::draw() {
    faro.draw();
    if (bLight) {
        faro.enable();
    }
    else {
        faro.disable();
    }

    // CLASE PADRE: se hace siempre si no se carga un modelo
    material.begin();
    {
        collider.draw();
    }
    material.end();
}

void Player::drawDebug() {
    // CLASE PADRE
    collider.drawWireframe();

    transform.transformGL();
    // se dibujan también los axis
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions() {
    // se obtienen todos los objetos con los que ha colisionado
    vector<GameObject*> collisions = game->getCollisions(this);
    for (auto c : collisions) {
        // los objetos con los que ha colisionado hacen lo oportuno
        c->receiveCarCollision(this);
    }
}

void keyPressed(int key) {

}

void Player::steerLeft() {
    transform.rotateDeg(1, 0, 2, 0);
}

void Player::steerRight() {
    transform.rotateDeg(-1, 0, 2, 0);
}

void Player::accelerate() {
    speed += 0.1;
}

void Player::brake() {
    speed -= 0.1;
}

void Player::stop() {
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::toggleLight() {
    bLight = !bLight;
}

float Player::getSpeed() {
    return speed;
}

void Player::addCoins(int n) {
    coins += n;
}

int Player::getCoins() {
    return coins;
}
