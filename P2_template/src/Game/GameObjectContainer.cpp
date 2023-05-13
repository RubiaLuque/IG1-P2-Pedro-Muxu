#include "GameObjectContainer.h"
#include "../Structure/GameObject.h"
#include "../Utils/checkML.h"

GameObjectContainer::GameObjectContainer() {}

void GameObjectContainer::add(GameObject* g){
    gameObjects.push_back(g);
}

GameObjectContainer::~GameObjectContainer(){
    clear();
}

void GameObjectContainer::update(){
    for(auto g: gameObjects){
        if(g->isAlive()){
            // se actualizan todos los objetos
            g->update();
            // se comprueban las colisiones de los objetos
            g->checkCollisions();
        }
    }
    // se eliminan los objetos no vivos
    removeDead();
}

void GameObjectContainer::draw(){
    for(auto g: gameObjects){
        if(g->isAlive()){
            g->draw();
        }
    }
}
void GameObjectContainer::drawDebug(){
    for(auto g: gameObjects){
        g->drawDebug();
    }
}

void GameObjectContainer::removeDead() {
    vector<GameObject*> alive;
    for (auto g : gameObjects) {
        if (g->isAlive()) {
            alive.push_back(g);
        }
        else {
            delete g;
        }
    }
    gameObjects.clear();
    gameObjects = alive;
}

void GameObjectContainer::clear() {
    for (auto g : gameObjects) {
        delete g;
    }
    gameObjects.clear();
}

vector<GameObject*> GameObjectContainer::getCollisions(GameObject* gameObject) {
    vector<GameObject*> collisions;
    // se obtienen en un vector los objetos con los que ha colisionado el objeto
    for (auto other : gameObjects) {
        // no se tienen en cuenta ni el propio objeto ni los no vivos
        if (gameObject != other && other->isAlive()) {
            if (gameObject->collide(other)) {
                collisions.push_back(other);
            }
        }
    }
    return collisions;
}
