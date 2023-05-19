#include "GameObjectContainer.h"
#include "../Structure/GameObject.h"
#include "CollisionEngine.h"

// SE UTILIZA PARA ALTERNAR ENTRE LAS FÍSICAS CON Y SIN LIBRERÍA
//#define LIBRARY

GameObjectContainer::GameObjectContainer() : collisionEngine(nullptr) {
    // LIBRERÍA FÍSICAS
#ifdef LIBRARY
    collisionEngine = new CollisionEngine(gameObjects);
#endif
}

void GameObjectContainer::add(GameObject* g) {
    gameObjects.push_back(g);
    // LIBRERÍA FÍSICAS
#ifdef LIBRARY
    collisionEngine->add(g);
#endif
}

GameObjectContainer::~GameObjectContainer(){
    clear();
    if (collisionEngine != nullptr) {
        delete collisionEngine;
    }
}

void GameObjectContainer::update() {
    // se actualizan todos los objetos
    for (auto g : gameObjects) {
        if (g->isAlive()) {
            g->update();
        }
    }

    // LIBRERÍA FÍSICAS
    // se mueven sus colliders
#ifdef LIBRARY
    collisionEngine->update();
#endif

    // se comprueban las colisiones
    for (auto g : gameObjects) {
        if (g->isAlive()) {
            g->checkCollisions();
        }
    }

    // se eliminan los muertos
    removeDead();
}

void GameObjectContainer::draw(bool isUIElement) {
    for (auto g : gameObjects) {
        bool isUI = g->isUIElement() == isUIElement;
        if (g->isAlive() && isUI) {
            g->draw();
        }
    }
}

void GameObjectContainer::drawDebug(bool isUIElement) {
    for (auto g : gameObjects) {
        bool isUI = g->isUIElement() == isUIElement;
        if (isUI) {
            g->drawDebug();
        }
    }
}

void GameObjectContainer::handleInput() {
    for (auto g : gameObjects) {
        if (g->isAlive()) {
            g->handleInput();
        }
    }
}

void GameObjectContainer::removeDead() {
    vector<GameObject*> alive;
    for (auto g : gameObjects) {
        if (g->isAlive()) {
            alive.push_back(g);
        }
        else {
            // LIBRERÍA FÍSICAS
#ifdef LIBRARY
            collisionEngine->remove(g);
#endif
            delete g;
        }
    }
    gameObjects.clear();
    gameObjects = alive;
}

void GameObjectContainer::clear() {
    for (auto g : gameObjects) {
        // LIBRERÍA FÍSICAS
#ifdef LIBRARY
        collisionEngine->remove(g);
#endif
        delete g;
    }
    gameObjects.clear();
}

vector<GameObject*> GameObjectContainer::getCollisions(GameObject* gameObject) {
    // LIBRERÍA FÍSICAS
#ifdef LIBRARY
    return collisionEngine->getCollisions(gameObject);

#else
    // NO LIBRERÍA FÍSICAS
    vector<GameObject*> collisions;
    // se obtienen en un vector los objetos con los que ha colisionado el objeto
    for (auto other : gameObjects) {
        // no se tienen en cuenta ni el propio objeto ni los no vivos ni los elementos del UI
        if (gameObject != other && other->isAlive() && !other->isUIElement()) {
            if (gameObject->collide(other)) {
                collisions.push_back(other);
            }
        }
    }
    return collisions;
#endif
}
