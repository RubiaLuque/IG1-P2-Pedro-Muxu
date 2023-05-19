#include "BoxCollider.h"
#include "../Structure/GameObject.h"
#include "../Utils/checkML.h"

#ifdef INCLUDE_LIBRARY
#include "ofxBullet.h"
#endif

void BoxCollider::drawDebug() {
    ofPushStyle();
    {
        drawWireframe();
#ifdef INCLUDE_LIBRARY
        // NOTE uncomment to see bullet collider
        if (collisionObject != nullptr) {
            collisionObject->draw();
        }
#endif
    }
    ofPopStyle();
}