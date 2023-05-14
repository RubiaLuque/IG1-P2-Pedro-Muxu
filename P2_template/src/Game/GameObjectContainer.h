
#ifndef GameObjectContainer_h
#define GameObjectContainer_h

#include "ofMain.h"

class GameObject;
class CollisionEngine;

class GameObjectContainer {
private:
    vector<GameObject*> gameObjects;
    CollisionEngine* collisionEngine;

    // eliminar todos los objetos no vivos
    // se ejecuta despu�s del update
    void removeDead();

    // eliminar todos los objetos
    void clear();

public:
    GameObjectContainer();
    ~GameObjectContainer();

    // a�adir un objeto
    void add(GameObject* g);

    // actualizar todos los objetos vivos
    void update();
    // dibujar todos los objetos vivos
    void draw();
    // dibujar las cajas de colisiones de los objetos vivos
    void drawDebug();
    void handleInput();

    // obtener los objetos con los que est� colisionando otro objeto
    vector<GameObject*> getCollisions(GameObject* gameObject);
};
#endif 
