#include "GameObject.h"
#include "../Utils/checkML.h"

GameObject::GameObject(Game* game, glm::vec3 pos) : game(game) {
    collider.setParent(transform);
    transform.setPosition(pos);
    bAlive = true;
}

GameObject::~GameObject() { }

void GameObject::drawDebug() {
    collider.drawWireframe();
}
