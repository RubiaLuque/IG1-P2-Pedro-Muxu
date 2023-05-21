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
    inputActivated = false;
    falling = true;
}

void Player::skid() {
    counter++;
    inputActivated = false;
    transform.rotateRad(ofRandom(0, PI), 0, 1, 0);
    ofSoundPlayer skidSound = game->getSkidSound();
    skidSound.play();
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

void Player::counterShot() {
    // contador para poder volver a disparar una bala
    if (bulletFired) {
        elapsedTime += ofGetLastFrameTime();
        if (elapsedTime > BULLET_TIMER) {
            elapsedTime = 0;
            bulletFired = false;
        }
    }
}

void Player::counterFalling() {
    if (falling) {
        fallingTime += ofGetLastFrameTime();
        if (fallingTime >= FALLING_TIMER) {
            fallingTime = 0;
            falling = false;
            inputActivated = true;
            resetPos();
        }
    }
}

void Player::counterSkidding() {
    if (skidding && counter < 1) {
        skid();
        skiddingTime += ofGetLastFrameTime();
    }

    if (skidding && skiddingTime < SKIDDING_TIME) {
        skiddingTime += ofGetLastFrameTime();
        if (skiddingTime > SKIDDING_TIME) {
            inputActivated = true;
            skidding = false;
            counter = 0;
            skiddingTime = 0;
        }
    }
}

Player::Player(Game* game, glm::vec3 pos) :GameObject(game, pos, glm::vec3(1.5 * HEIGHT, HEIGHT, 3 * HEIGHT)),
speed(0), bLight(false), coins(0), elapsedTime(0), bulletFired(false), rotation(0), inputActivated(true), originalPos(0),
verticalSpeed(0), falling(false), fallingTime(0), skidding(false), skiddingTime(0), counter(0) {

    assert(model.loadModel(MODEL_PATH));
    // ajustar el modelo al collider
    model.setRotation(0, 180, 1, 0, 100);
    float scale = HEIGHT / (500.0 / 3.0);
    model.setScale(scale, scale, scale);
    glm::vec3 modelPos = model.getPosition();
    model.setPosition(modelPos.x, modelPos.y - HEIGHT / 2.3, modelPos.z);

    // todos los objetos se mueven a partir de su nodo
    // se hace que el faro se hija de un nodo
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    // mover el faro
    faro.move(0, 0, 50);
    // rotarlo
    faro.rotateDeg(-200, 1, 0, 0);

    AreaRound* areaRound = new AreaRound(game, &transform, boxCollider);
    game->addGameObject(areaRound);
}

void Player::update() {
    // velocidad vertical que se reduce por la velocida si está en el aire
    verticalSpeed += -GRAVITY * GRAVITY_SCALE * ofGetLastFrameTime();

    // parar al jugador si llega al suelo y no está cayendo
    if (isOnGround() && verticalSpeed < 0 && !falling) {
        verticalSpeed = 0;
        glm::vec3 actPos = transform.getPosition();
        transform.setPosition(actPos.x, originalPos.y, actPos.z);
    }

    // salto
    if (ofGetKeyPressed(game->OF_KEY_SPACE) && isOnGround() && inputActivated) {
        verticalSpeed = JUMPFORCE;
    }

    // mover al jugador hacia abajo
    transform.move(transform.getYAxis() * verticalSpeed * ofGetLastFrameTime());

    continuousInput();

    move();

    counterShot();

    counterFalling();

    counterSkidding();
}

void Player::draw() {
    faro.draw();
    if (bLight) {
        faro.enable();
    }
    else {
        faro.disable();
    }

    transform.transformGL();
    {
        model.drawFaces();
    }
    transform.restoreTransformGL();
}

void Player::drawDebug() {
    GameObject::drawDebug();

    transform.transformGL();
    // se dibujan también los axis
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