#include "CollisionEngine.h"
#include "../Structure/GameObject.h"
#include "Game.h"
#include "../Utils/checkML.h"
#define BT_USE_DOUBLE_PRECISION

CollisionEngine::CollisionEngine(vector <GameObject*>& colliders) :colliders(colliders) {
    world.setup();
    // se desactiva la gravedad, el agarre y los eventos de colisiones
    world.setGravity(ofVec3f(0, 0, 0));
    world.disableGrabbing();
    world.disableCollisionEvents();
};

CollisionEngine::~CollisionEngine() {
    world.destroy();
};

void CollisionEngine::add(GameObject* g) {
    // se crea una caja de colisión para el objeto a partir de la caja primitiva del openFrameworks
    ofxBulletBox* box = new ofxBulletBox();
    BoxCollider* b = g->getCollider();
    // tamaño de la caja de colisiones
    box->init(ofBtGetBoxCollisionShape(b->getWidth(), b->getHeight(), b->getDepth()));
    // se coloca en el mundo
    box->create(world.world, b->getGlobalPosition());
    box->setActivationState(DISABLE_DEACTIVATION);
    // añadir al sistema de físicas
    box->add();
    box->enableKinematic();
    if (!g->isFixed()) {
        box->activate();
    }
    b->collisionObject = box;

    // se mueve la caja de colisión
    updateObject(g);

};

void CollisionEngine::updateObject(GameObject* g) {
    BoxCollider* b = g->getCollider();
    btTransform transform;
    b->collisionObject->getRigidBody()->getMotionState()->getWorldTransform(transform);
    transform.setFromOpenGLMatrix(glm::value_ptr(b->getGlobalTransformMatrix()));
    b->collisionObject->getRigidBody()->getMotionState()->setWorldTransform(transform);
}

void CollisionEngine::update() {
    for (auto g : colliders) {
        // si no está activado, no se mueve el collider
        // porque se trata de un objeto fijo
        if (!g->isFixed()) {
            updateObject(g);
        }
    }
    world.update(0.1, 1);
};

vector<GameObject*> CollisionEngine::getCollisions(GameObject* g) {
    // comprobar si dos objetos han colisionado
    struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
    {
        bool bCollison;
        MyContactResultCallback() {
            bCollison = false;
        }
        virtual btScalar addSingleResult(btManifoldPoint& cp, const btCollisionObjectWrapper* colObj0Wrap, int partId0, int index0, const btCollisionObjectWrapper* colObj1Wrap, int partId1, int index1)
        {
            bCollison = true;
            return 0;
        }
    };

    vector<GameObject*> collisions;
    // se obtienen todas las colisiones del mundo
    auto cw = world.getWorld()->getCollisionWorld();

    for (auto other : colliders) {
        if (g != other) {
            MyContactResultCallback resultCallback;
            // se comprueba si ha contacto entre el objeto deseado y el otro
            cw->contactPairTest(g->getCollider()->collisionObject->getCollisionObject(), other->getCollider()->collisionObject->getCollisionObject(), resultCallback);
            if (resultCallback.bCollison) {
                collisions.push_back(other);
            }
        }

    }
    return collisions;
};

void CollisionEngine::remove(GameObject* g) {
    g->getCollider()->collisionObject->remove();
    delete g->getCollider()->collisionObject;
};