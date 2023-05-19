#include "GameObjectContainer.h"
#include "../Structure/GameObject.h"

#ifdef INCLUDE_LIBRARY
#include "CollisionEngine.h"
#endif

GameObjectContainer::GameObjectContainer() {
    gameObjects.reserve(APROX_GAMEOBJECTS);

#ifdef INCLUDE_LIBRARY
    collisionEngine = nullptr;

    // LIBRERÍA FÍSICAS
#ifdef USE_LIBRARY
    collisionEngine = new CollisionEngine(gameObjects);
#endif

#endif
}

void GameObjectContainer::add(GameObject* g) {
    gameObjects.push_back(g);
    // LIBRERÍA FÍSICAS
#if defined(INCLUDE_LIBRARY) && defined(USE_LIBRARY)
    collisionEngine->add(g);
#endif
}

GameObjectContainer::~GameObjectContainer() {
    clear();

#ifdef INCLUDE_LIBRARY
    if (collisionEngine != nullptr) {
        delete collisionEngine;
    }
#endif
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
#if defined(INCLUDE_LIBRARY) && defined(USE_LIBRARY)
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
#if defined (INCLUDE_LIBRARY) && defined(USE_LIBRARY)
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
#if defined (INCLUDE_LIBRARY) && defined(USE_LIBRARY)
        collisionEngine->remove(g);
#endif
        delete g;
    }
    gameObjects.clear();
}

vector<GameObject*> GameObjectContainer::getCollisions(GameObject* gameObject) {
    // LIBRERÍA FÍSICAS
#if defined (INCLUDE_LIBRARY) && defined(USE_LIBRARY)
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
