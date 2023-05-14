#include "Pedestrian.h"
#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"

Pedestrian::Pedestrian(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim),
speed(6), bTurned(false), modelPath("astroBoy_walk.dae") {

    // ajustar el collider de acuerdo al modelo
    boxCollider->move(0, dim.y / 2 - 25, 0);

    // cargar el modelo
    assert(model.loadModel(modelPath));

    // colocar inicialmente el modelo
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    model.setScale(0.25, 0.25, 0.25);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();

    // a partir de ahora todas las transformaciones se realizan
    // con nodo
    transform.rotateDeg(90, 0, 1, 0);
}

void Pedestrian::update() {
    model.update();
    // mover collider y modelo
    transform.move(transform.getZAxis() * -speed);
    bTurned = false;
};

void Pedestrian::draw() {
    // el modelo se mueve con las transformaciones del nodo
    transform.transformGL();
    {
        model.drawFaces();
    }
    transform.restoreTransformGL();
};

void Pedestrian::receiveCarCollision(Player* car) {
    bAlive = false;
    //game->doScream();
};

//void Pedestrian::receiveBulletCollision(GameObject* bullet) {
//
//    bullet->kill();
//    kill();
//    game->getPlayer()->addCoins(1000);
//
//};

void Pedestrian::turn() {
    if (!bTurned) {
        transform.rotateDeg(180, 0, 1, 0);
        transform.move(transform.getZAxis() * -speed);
        bTurned = true;
    }
}

//void Pedestrian::checkCollisions() {
//    vector<GameObject*> collisions = game->getCollisions(this);
//    for (auto c : collisions) {
//        c->receivePedestrianCollision(this);
//    }
//}