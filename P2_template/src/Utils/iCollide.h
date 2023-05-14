#ifndef iColllide_h
#define iColllide_h

#include "ofMain.h"
#include "BoxCollider.h"

class Player;

class iCollide {

protected:
    BoxCollider* boxCollider;

public:
    iCollide() {
        boxCollider = new BoxCollider();
    }

    virtual ~iCollide() {
        delete boxCollider;
    }

    // el propio objeto es el encargado de comprobar la colisiones con los demás objetos
    // los objetos que colisionen con el jugador deberán implementar este método
    virtual void receiveCarCollision(Player* car) {};

    BoxCollider* getCollider() {
        return boxCollider;
    }

    // NO LIBRERÍA FÍSICAS
    bool collide(iCollide* other) {
        BoxCollider* otherCollider = other->getCollider();
        glm::vec3 p0 = boxCollider->getGlobalPosition();
        glm::vec3 d0 = boxCollider->getSize();
        glm::vec3 p1 = otherCollider->getGlobalPosition();
        glm::vec3 d1 = otherCollider->getSize();
        if (p0.x + d0.x / 2 > p1.x - d1.x / 2 && p0.x - d0.x / 2 < p1.x + d1.x / 2) {
            if (p0.y + d0.y / 2 > p1.y - d1.y / 2 && p0.y - d0.y / 2 < p1.y + d1.y / 2) {
                if (p0.z + d0.z / 2 > p1.z - d1.z / 2 && p0.z - d0.z / 2 < p1.z + d1.z / 2) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif /* iColllide_h */
