
#ifndef BoxCollider_h
#define BoxCollider_h

#include "ofMain.h"

class GameObject;

#ifdef LIBRARY
class ofxBulletRigidBody;
class CollisionEngine;
#endif

// Collider caja
// Funciona como un almacén de la caja primitiva de openFrameworks y la caja de la librería de físicas
// La creacíón, propiedades y destrucción de la caja de la librería corren a cargo de CollisionEngine
// CollisionEngine da las propiedades a la caja de físicas de la librería a partir de las dadas
// a la caja primitiva de openFrameworks
class BoxCollider : public ofBoxPrimitive {
public:
#ifdef LIBRARY
    friend CollisionEngine;
#endif
private:
#ifdef LIBRARY
    // caja de la librería de físicas
    ofxBulletRigidBody* collisionObject;
#endif

public:
    BoxCollider() {
#ifdef LIBRARY
        collisionObject = nullptr;
#endif
    }

    void drawDebug();
};

#endif /* BoxCollider_h */

