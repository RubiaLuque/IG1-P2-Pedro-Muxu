#include "CrazyBow.h"
#include "Player.h"

CrazyBow::CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim, int nBlocksLong, int nBlocksHigh, int blockSize, glm::vec4 rotation, int nMaxCoins) :
    GameObject(game, pos, dim), blockSize(blockSize), nBlocksLong(nBlocksLong), nBlocksHigh(nBlocksHigh), nMaxCoins(nMaxCoins), canPass(true), elapsedTime(0) {
    material.setEmissiveColor(ofColor::red);
    transform.rotateDeg(rotation.x, rotation.y, rotation.z, rotation.w);

    nRandomCoins = (int)ofRandom(1, nMaxCoins + 1);
}

void CrazyBow::update() {
    if (!canPass) {
        elapsedTime *= ofGetLastFrameTime();
        if (elapsedTime > TIMER) {
            canPass = true;
            elapsedTime = 0;
        }
    }
}

void CrazyBow::draw() {
    material.begin();
    {
        transform.transformGL();
        {
            // palo izquierdo
            ofDrawBox(boxCollider->getWidth() / 2, 0, 0, blockSize, boxCollider->getHeight(), blockSize);
            ofDrawBox(boxCollider->getWidth() / 2 - nBlocksLong / 2 * blockSize, boxCollider->getHeight() / 2, 0, nBlocksLong * blockSize + blockSize, blockSize, blockSize);
            ofDrawBox(boxCollider->getWidth() / 2 - nBlocksLong * blockSize, boxCollider->getHeight() / 2 + nBlocksHigh / 2 * blockSize, 0, blockSize, nBlocksHigh * blockSize, blockSize);
            // palo derecho
            ofDrawBox(-boxCollider->getWidth() / 2, 0, 0, blockSize, boxCollider->getHeight(), blockSize);
            ofDrawBox(-boxCollider->getWidth() / 2 + nBlocksLong / 2 * blockSize, boxCollider->getHeight() / 2, 0, nBlocksLong * blockSize + blockSize, blockSize, blockSize);
            ofDrawBox(-boxCollider->getWidth() / 2 + nBlocksLong * blockSize, boxCollider->getHeight() / 2 + nBlocksHigh / 2 * blockSize, 0, blockSize, nBlocksHigh * blockSize, blockSize);
            // palo horizontal central
            ofDrawBox(0, boxCollider->getHeight() / 2 + nBlocksHigh * blockSize, 0, boxCollider->getWidth() - 2 * nBlocksLong * blockSize + blockSize, blockSize, blockSize);
        }
        transform.restoreTransformGL();
    }
    material.end();
}

void CrazyBow::receiveCarCollision(Player* car) {
    if (canPass) {
        car->addCoins(nRandomCoins);
        nRandomCoins = (int)ofRandom(1, nMaxCoins + 1);
        canPass = false;
    }
}