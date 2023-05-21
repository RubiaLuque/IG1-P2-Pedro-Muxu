#include "Pedestrian.h"
#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"
#include "Bullet.h"

Pedestrian::Pedestrian(Game* game, glm::vec3 pos, float height, glm::vec4 rotation) :
    GameObject(game, pos, glm::vec3(height / 4, height, height / 4)) {
    // cargar el modelo
    assert(model.loadModel(MODEL_PATH));

    // rotar el modelo
    model.setRotation(0, 180, 1, 0, 0);

    // ajustar el collider de acuerdo al modelo
    boxCollider->move(0, height / 2, 0);
    model.setScale(height / 800, height / 800, height / 800);

    // animación
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();

    // rotar el personaje para que camine en la dirección adecuada
    transform.rotateDeg(rotation.x, rotation.y, rotation.z, rotation.w);
}

void Pedestrian::update() {
    // ejecutar animación del modelo
    model.update();
    // mover collider y modelo
    transform.move(transform.getZAxis() * -SPEED * ofGetLastFrameTime());
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
    kill();
    car->addCoins(100);
    ofSoundPlayer scream = game->getSound(ecs::_sound_SCREAM);
    scream.play();
};

void Pedestrian::receiveBulletCollision(Bullet* bullet) {
    // se elimina la bala
    bullet->kill();

    //grita
    ofSoundPlayer scream = game->getSound(ecs::_sound_SCREAM);
    scream.play();

    // se elimina a sí mismo
    kill();
    game->getPlayer()->addCoins(100);
};

void Pedestrian::checkCollisions() {
    vector<GameObject*> collisions = game->getCollisions(this);
    for (auto c : collisions) {
        c->receivePedestrianCollision(this);
    }
}

void Pedestrian::turnBack() {
    // se rota
    transform.rotateDeg(180, 0, 1, 0);
    // moverlo un paso para evitar que detecte de nuevo la colisión
    transform.move(transform.getZAxis() * -SPEED * ofGetLastFrameTime());
}