#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"
#include "Bullet.h"
#include "AreaRound.h"

void Player::move() {
    prevPos = transform.getPosition();
    transform.move(transform.getZAxis() * speed * ofGetLastFrameTime());

    if (speed > MAX_SPEED) {
        speed = MAX_SPEED;
    }
    else if (speed < 0) {
        speed = 0;
    }
}

void Player::fall() {
    setInputActivated(false);
    falling = true;
}

void Player::continuousInput() {
    // como se trata de movimiento continuo es mejor ponerlo en el update
    if (inputActivated) {
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
    }
}

void Player::jump() {
    verticalSpeed += -GRAVITY * GRAVITY_SCALE * ofGetLastFrameTime();
    if (isOnGround() && verticalSpeed < 0) {
        verticalSpeed = 0;
        glm::vec3 actPos = transform.getPosition();
        transform.setPosition(actPos.x, originalPos.y, actPos.z);
    }
    if (ofGetKeyPressed(game->OF_KEY_SPACE) && isOnGround() && inputActivated) {
        verticalSpeed = JUMPFORCE;
    }
    transform.move(transform.getYAxis() * verticalSpeed * ofGetLastFrameTime());
}

Player::Player(Game* game, glm::vec3 pos) :GameObject(game, pos, glm::vec3(SIZE)),
speed(0), bLight(false), coins(0), elapsedTime(0), bulletFired(false), rotation(0), inputActivated(true), originalPos(0),
verticalSpeed(0), falling(false), fallingTime(0) {
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

    AreaRound* areaRound = new AreaRound(game, &transform, SIZE);
    game->addGameObject(areaRound);
}

void Player::update() {

    jump();

    continuousInput();

    move();

    // contador para poder volver a disparar una bala
    if (bulletFired) {
        elapsedTime += ofGetLastFrameTime();
        if (elapsedTime > BULLET_TIMER) {
            elapsedTime = 0;
            bulletFired = false;
        }
    }

    if (falling) {
        transform.move(transform.getYAxis() * FALL_OFFSET * ofGetLastFrameTime());
        //transform.setPosition({ transform.getX(), transform.getY() - FALL_OFFSET, transform.getZ() });
        fallingTime += ofGetLastFrameTime();
        if (fallingTime >= FALLING_TIMER) {
            fallingTime = 0;
            falling = false;
            setInputActivated(true);
            resetPos();
        }
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

    transform.transformGL();
    // se dibujan tambi�n los axis
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::handleInput() {
    if (inputActivated) {
        if (ofGetKeyPressed('l')) {
            toggleLight();
        }
        else if (ofGetKeyPressed('s')) {
            if (coins > 0 && !bulletFired) {
                --coins;
                bulletFired = true;
                // disparar bala
                // pasamos siempre datos globales
                Bullet* bullet = new Bullet(game, transform.getGlobalPosition(), transform.getGlobalOrientation());
                game->addGameObject(bullet);
            }
        }
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