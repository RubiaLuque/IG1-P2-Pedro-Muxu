#include "Goal.h"
#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"

Goal::Goal(Game* game, glm::vec3 pos, glm::vec3 dim, int sizeBars) : GameObject(game, pos, dim), sizeBars(sizeBars) {
    // material
    material.setEmissiveColor(ofColor::green);
}

// como lo que se quiere mostrar no corresponde con el modelo, se redefine el método
// sin embargo, el drawDebug no se redefine porque ahí lo que interesa es ver el collider
void Goal::draw() {
    material.begin();
    {
        // la meta está formada por varios cubos del mismo tamaño
        // todos los cubos se tienen que colocar con las transformaciones del nodo
        transform.transformGL();
        {
            ofDrawBox(-boxCollider->getWidth() / 2, 0, 0, sizeBars, boxCollider->getHeight(), sizeBars);
            ofDrawBox(boxCollider->getWidth() / 2, 0, 0, sizeBars, boxCollider->getHeight(), sizeBars);
            ofDrawBox(0, boxCollider->getHeight() / 2, 0, boxCollider->getWidth(), sizeBars, sizeBars);
        }
        transform.restoreTransformGL();
    }
    material.end();
}

void  Goal::receiveCarCollision(Player *car){
    car->stop();
    ofSoundPlayer winner = game->getSound(ecs::_sound_WINNER);
    winner.play();
    game->finishGame();
}
