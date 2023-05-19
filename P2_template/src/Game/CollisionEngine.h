#ifndef CollisionEngine_h
#define CollisionEngine_h
/*

#include "ofMain.h"
#include "ofxBullet.h"
class Game;
class GameObject;

class CollisionEngine {
private:
    // rigid del mundo
    // se utiliza para las distintas configuraciones, como la gravedad
    ofxBulletWorldRigid world;
    // objetos con los que comprobar colisiones, es decir, los que hay en el mundo
    vector <GameObject*>& colliders;

    // se utiliza para ir moviendo la caja de colisi�n constantemente
    void updateObject(GameObject*);

public:
    CollisionEngine(vector <GameObject*>& colliders);
    ~CollisionEngine();

    // mover constantemente los colliders de los gameobjects
    void update();

    // a�adir un objeto a la detecci�n de colisiones
    void add(GameObject* g);

    // eliminar el collider
    void remove(GameObject* g);

    // devuelve los objetos con los que est� colisionando un gameobject
    vector<GameObject*> getCollisions(GameObject* g);
};

*/
#endif /* CollisionEngine_h */