
#ifndef BoxCollider_h
#define BoxCollider_h

#include "ofMain.h"

class GameObject;
class ofxBulletRigidBody;
class CollisionEngine;

// Collider caja
// Funciona como un almacén de la caja primitiva de openFrameworks y la caja de la librería de físicas
// La creacíón, propiedades y destrucción de la caja de la librería corren a cargo de CollisionEngine
// CollisionEngine da las propiedades a la caja de físicas de la librería a partir de las dadas
// a la caja primitiva de openFrameworks
class BoxCollider : public ofBoxPrimitive {
public:
    friend CollisionEngine;

private:
    // caja de la librería de físicas
    ofxBulletRigidBody* collisionObject;

public:
    BoxCollider() : collisionObject(nullptr) { }

    void drawDebug();
};

#endif /* BoxCollider_h */
