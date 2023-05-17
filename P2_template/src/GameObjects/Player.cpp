#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"

Player::Player(Game* game) :GameObject(game, glm::vec3(0, 0, 0), glm::vec3(100)),
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
}

void Player::update() {
    // INPUT
    // como se trata de movimiento continuo es mejor ponerlo en el update
    // rotar
    if (ofGetKeyPressed(OF_KEY_LEFT)) {
        steerLeft();
    }
    else if (ofGetKeyPressed(OF_KEY_RIGHT)) {
        steerRight();
    }
    if (ofGetKeyPressed(OF_KEY_UP)) {
        accelerate();
    }
    else if (ofGetKeyPressed(OF_KEY_DOWN)) {
        brake();
    }

    // MOVERLO
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

    // se hace siempre que el objeto que se quiera pintar corresponda con su collider
    GameObject::draw();
}

void Player::drawDebug() {
    GameObject::drawDebug();
    //collider.drawWireframe();

    transform.transformGL();
    // se dibujan tambi�n los axis
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::handleInput() {
    if (ofGetKeyPressed('l')) {
        toggleLight();
    }
}

void Player::checkCollisions() {
    // se obtienen todos los objetos con los que ha colisionado
    vector<GameObject*> collisions = game->getCollisions(this);
    for (auto c : collisions) {
        // los objetos con los que ha colisionado hacen lo oportuno
        c->receiveCarCollision(this);
    }
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

void Player::addCoins(int n) {
    coins += n;
}

int Player::getCoins() {
    return coins;
}
