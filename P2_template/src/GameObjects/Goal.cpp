#include "Goal.h"
#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"

Goal::Goal(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
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
        transform.transformGL(); {
            ofDrawBox(-boxCollider->getWidth() / 2, 250, 0, 50, 500, 50);
            ofDrawBox(boxCollider->getWidth() / 2, 250, 0, 50, 500, 50);
            ofDrawBox(0, 500, 0, boxCollider->getWidth(), 50, 50);
        }
        transform.restoreTransformGL();
    }
    material.end();
}

void  Goal::receiveCarCollision(Player *car){
    car->stop();
    game->finishGame();
}
