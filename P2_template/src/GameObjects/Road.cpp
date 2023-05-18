#include "Road.h"
#include "Game.h"
#include "../Utils/checkML.h"

void Road::enableLight(bool enable) {
    if (enable) {
        light.enable();
    }
    else {
        light.disable();
    }
}

Road::Road(Game* game, glm::vec3 pos, glm::vec3 dim, bool lightEnabled) :
    GameObject(game, pos, dim), lightEnabled(lightEnabled) {

    // CARRETERA
    plane.setParent(transform);

    // color
    material.setDiffuseColor(ofColor::darkGrey);
    // rotar el plano
    transform.rotateDeg(-90, 1, 0, 0);
    // cambiar el tamaño
    plane.set(dim.x, dim.z);

    // LUZ DE LA CARRETERA
    // posición
    light.setPosition(pos.x, 350, pos.z);
    light.setAttenuation(2);
    //light.setPosition(200, 200, 200);
    light.setDiffuseColor(ofColor::white);
}

void Road::draw() {
    enableLight(lightEnabled);
    material.begin();
    {
        plane.draw();
    }
    material.end();
}

void Road::drawDebug(){
    plane.drawWireframe();
}