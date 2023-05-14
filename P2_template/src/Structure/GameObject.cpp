#include "GameObject.h"
#include "../Utils/checkML.h"

GameObject::GameObject(Game* game, glm::vec3 pos, glm::vec3 dim) : game(game), fixed(false), bAlive(true) {
    boxCollider->setParent(transform);
    transform.setPosition(pos);
    boxCollider->set(dim.x, dim.y, dim.z);
}

void GameObject::draw() {
    material.begin();
    {
        boxCollider->draw();
    }
    material.end();
}

void GameObject::drawDebug() {
    boxCollider->drawDebug();
}
