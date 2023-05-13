#include "Wall.h"
#include "Player.h"
#include "../Utils/checkML.h"

Wall::Wall(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos) {
    // tamaño
    collider.set(dim.x, dim.y, dim.z);
    // color
    material.setEmissiveColor(ofColor::darkorange);
}
Wall::~Wall(){}

void Wall::draw(){
    material.begin();
    {
        collider.draw();
    }
    material.end();
}

void  Wall::receiveCarCollision(Player *car){
    car->stop();
}
