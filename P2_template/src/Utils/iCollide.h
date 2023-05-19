#ifndef iColllide_h
#define iColllide_h

#include "ofMain.h"
#include "BoxCollider.h"

class Player;
class Bullet;
class Pedestrian;
class Bomb;

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

    // el propio objeto es el encargado de comprobar las colisiones con los dem�s objetos
    virtual void receiveCarCollision(Player* car) {};
    virtual void receiveBulletCollision(Bullet* bullet) {};
    virtual void receivePedestrianCollision(Pedestrian* pedestrian) {};
    virtual void receiveBombCollision(Bomb* bomb) {}

    BoxCollider* getCollider() {
        return boxCollider;
    }

    // NO LIBRER�A F�SICAS
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
