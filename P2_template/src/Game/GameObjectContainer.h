
#ifndef GameObjectContainer_h
#define GameObjectContainer_h

#include "ofMain.h"

class GameObject;
#ifdef LIBRARY
class CollisionEngine;
#endif

class GameObjectContainer {
private:
    vector<GameObject*> gameObjects;

#ifdef LIBRARY
    CollisionEngine* collisionEngine;
#endif

    // eliminar todos los objetos no vivos
    // se ejecuta después del update
    void removeDead();

    // eliminar todos los objetos
    void clear();

public:
    GameObjectContainer();
    ~GameObjectContainer();

    // añadir un objeto
    void add(GameObject* g);

    // actualizar todos los objetos vivos
    void update();
    // dibujar todos los objetos vivos
    void draw(bool isUIElement);
    // dibujar las cajas de colisiones de los objetos vivos
    void drawDebug(bool isUIElement);
    void handleInput();

    // obtener los objetos con los que está colisionando otro objeto
    vector<GameObject*> getCollisions(GameObject* gameObject);
};
#endif 
