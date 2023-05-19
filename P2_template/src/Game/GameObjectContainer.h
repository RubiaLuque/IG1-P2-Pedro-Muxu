
#ifndef GameObjectContainer_h
#define GameObjectContainer_h

#include "ofMain.h"
class GameObject;

// incluir la librería de físicas en el proyecto
// BoxCollider, CollisionEngine, GameObjectContainer
//#define INCLUDE_LIBRARY
// usar la librería de física o no
// tiene que estar incluida la librería de físicas en el proyecto
//#define USE_LIBRARY

#ifdef INCLUDE_LIBRARY
class CollisionEngine;
#endif

class GameObjectContainer {
private:
    const int APROX_GAMEOBJECTS = 100;

    vector<GameObject*> gameObjects;

#ifdef INCLUDE_LIBRARY
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
