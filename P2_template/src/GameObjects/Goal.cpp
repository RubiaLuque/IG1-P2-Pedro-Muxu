#include "Goal.h"
#include "Player.h"
#include "Game.h"
#include "../Utils/checkML.h"

Goal::Goal(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos){
    // tamaño
    collider.set(dim.x, dim.y, dim.z);
    // material
    material.setEmissiveColor(ofColor::green);
}
Goal::~Goal(){}

void Goal::draw(){
    
    material.begin();
    {
        // la meta está formada por varios cubos del mismo tamaño
        // todos los cubos se tienen que colocar con las transformaciones del nodo
        transform.transformGL(); {
            ofDrawBox(-collider.getWidth() / 2, 250, 0, 50, 500, 50);
            ofDrawBox(collider.getWidth() / 2, 250, 0, 50, 500, 50);
            ofDrawBox(0, 500, 0, collider.getWidth(), 50, 50);
        }
        transform.restoreTransformGL();
    }
    material.end();
}

void Goal::drawDebug(){
    collider.draw();
}

void  Goal::receiveCarCollision(Player *car){
    car->stop();
    game->finishGame();
}
