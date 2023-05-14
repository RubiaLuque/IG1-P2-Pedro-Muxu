#include "Road.h"
#include "Game.h"
#include "../Utils/checkML.h"

Road::Road(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    plane.setParent(transform);

    // CARRETERA
    // color
    material.setDiffuseColor(ofColor::darkGrey);
    // rotar el plano
    transform.rotateDeg(-90, 1, 0, 0);
    // cambiar el tama�o
    plane.set(dim.x, dim.z);

    // LUZ DE LA CARRETERA
    // posici�n
    light.setPosition(200, 200, 200);
    light.setDiffuseColor(ofColor::white);
}

void Road::draw() {
    light.enable();
    material.begin();
    {
        plane.draw();
    }
    material.end();
}

void Road::drawDebug(){
    plane.drawWireframe();
}
