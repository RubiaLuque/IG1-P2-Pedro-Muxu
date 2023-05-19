
#ifndef BoxCollider_h
#define BoxCollider_h

#include "ofMain.h"

class GameObject;

#ifdef LIBRARY
class ofxBulletRigidBody;
class CollisionEngine;
#endif

// Collider caja
// Funciona como un almac�n de la caja primitiva de openFrameworks y la caja de la librer�a de f�sicas
// La creac��n, propiedades y destrucci�n de la caja de la librer�a corren a cargo de CollisionEngine
// CollisionEngine da las propiedades a la caja de f�sicas de la librer�a a partir de las dadas
// a la caja primitiva de openFrameworks
class BoxCollider : public ofBoxPrimitive {
public:
#ifdef LIBRARY
    friend CollisionEngine;
#endif
private:
#ifdef LIBRARY
    // caja de la librer�a de f�sicas
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

