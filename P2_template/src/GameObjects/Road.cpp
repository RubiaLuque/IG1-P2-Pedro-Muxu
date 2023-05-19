#include "Road.h"
#include "Game.h"
#include "../Utils/checkML.h"

void Road::enableLight(bool enable, glm::vec2 roadCenter) {
    if (enable) {
        // posición
        light.setPosition(roadCenter.x, 200, roadCenter.y);
        // intensidad de la luz
        // cuanta menor es, mayor intensidad tiene
        light.setAttenuation(2);
        // cambiar de color
        light.setDiffuseColor(ofColor::white);

        // activar
        light.enable();
    }
    else {
        // desactivarla
        light.disable();
    }
}

Road::Road(Game* game, glm::vec3 pos, glm::vec3 dim, bool lightEnabled) :
    GameObject(game, pos, dim) {

    // CARRETERA
    plane.setParent(transform);
    // color
    material.setDiffuseColor(ofColor::darkGrey);
    // rotar el plano
    transform.rotateDeg(-90, 1, 0, 0);
    // cambiar el tamaño
    plane.set(dim.x, dim.z);

    // LUZ
    enableLight(lightEnabled, pos);
}

void Road::draw() {
    material.begin();
    {
        plane.draw();
    }
    material.end();
}

void Road::drawDebug(){
    plane.drawWireframe();
}