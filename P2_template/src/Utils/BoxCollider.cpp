#include "BoxCollider.h"
#include "../Structure/GameObject.h"
//#include "ofxBullet.h"
#include "../Utils/checkML.h"

void BoxCollider::drawDebug() {
    ofPushStyle();
    {
        drawWireframe();
        // NOTE uncomment to see bullet collider
        /*
        if (collisionObject != nullptr) {
            collisionObject->draw();
        }
        */
    }
    ofPopStyle();
}