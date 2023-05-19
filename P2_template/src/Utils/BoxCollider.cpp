#include "BoxCollider.h"
#include "../Structure/GameObject.h"
#include "../addons/ofxBullet/src/ofxBullet.h"
#include "../Utils/checkML.h"

void BoxCollider::drawDebug() {
    ofPushStyle();
    {
        drawWireframe();
        // NOTE uncomment to see bullet collider
#ifdef LIBRARY
        if (collisionObject != nullptr) {
            collisionObject->draw();
        }
#endif
    }
    ofPopStyle();
}