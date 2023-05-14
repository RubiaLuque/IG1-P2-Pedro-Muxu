
#ifndef BoxCollider_h
#define BoxCollider_h

#include "ofMain.h"

class GameObject;
class ofxBulletRigidBody;
class CollisionEngine;

// Collider caja
// Funciona como un almac�n de la caja primitiva de openFrameworks y la caja de la librer�a de f�sicas
// La creac��n, propiedades y destrucci�n de la caja de la librer�a corren a cargo de CollisionEngine
// CollisionEngine da las propiedades a la caja de f�sicas de la librer�a a partir de las dadas
// a la caja primitiva de openFrameworks
class BoxCollider : public ofBoxPrimitive {
public:
    friend CollisionEngine;

private:
    // caja de la librer�a de f�sicas
    ofxBulletRigidBody* collisionObject;

public:
    BoxCollider() : collisionObject(nullptr) { }

    void drawDebug();
};

#endif /* BoxCollider_h */
