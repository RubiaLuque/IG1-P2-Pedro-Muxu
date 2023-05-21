#include "CrazyBow.h"
#include "Player.h"
#include "../Game/Game.h"

void CrazyBow::bannerText(int num) {
    // no hace falta borrarlo lo que hay debajo porque se repinta encima
    string numString = to_string(nRandomCoins);

    // offset para colocar el número en el centro
    glm::vec2 offset = glm::vec2(-font.stringWidth(numString) / 2, font.stringHeight(numString) / 2);
    offset = game->convertToProperSize<glm::vec2>(offset, BANNER_LETTER_SIZE);

    // se dibuja un texto con un color
    fbo.begin();
    {
        ofPushStyle();
        {
            // fondo
            ofBackground(ofColor::white);

            // círculo
            // propiamente el círculo
            ofSetColor(ofColor::orangeRed);
            ofSetCircleResolution(80);
            ofDrawCircle(BANNER_WIDTH / 2, BANNER_HEIGHT / 2, BANNER_CIRCLE_RADIUS);
            // borde
            ofNoFill();
            ofSetColor(ofColor::black);
            ofDrawCircle(BANNER_WIDTH / 2, BANNER_HEIGHT / 2, BANNER_CIRCLE_RADIUS);

            // texto
            ofPushMatrix();
            {
                ofSetColor(ofColor::white);
                ofTranslate(BANNER_WIDTH / 2 + offset.x, BANNER_HEIGHT / 2 + offset.y);
                ofScale(game->getSizeRatio(BANNER_LETTER_SIZE));
                font.drawString(numString, 0, 0);
            }
            ofPopMatrix();
        }
        ofPopStyle();
    }
    fbo.end();
}

CrazyBow::CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim, int nBlocksLong, int nBlocksHigh, int blockSize, glm::vec4 rotation, int nMaxCoins) :
    GameObject(game, pos, dim), blockSize(blockSize), nBlocksLong(nBlocksLong), nBlocksHigh(nBlocksHigh), nMaxCoins(nMaxCoins), canPass(true), elapsedTime(0) {

    coinSound = game->getSound(ecs::_sound_SUPER_MARIO_COIN);

    material.setEmissiveColor(ofColor::red);
    transform.rotateDeg(rotation.x, rotation.y, rotation.z, rotation.w);

    // tamaño del canvas donde vamos a pintar
    // tiene su propio eje de coordenadas. (0,0) está arriba a la izquierda
    // se le ha dado el mismo tamaño que el de la pancarta, 
    // que es donde se va a utilizar su textura, para que sea intuitivo
    fbo.allocate(BANNER_WIDTH, BANNER_HEIGHT);
    // se limpia el canvas por si hubiera quedado algo pintado
    // sirve también solucionar errores o glitches que pudieran ocurrir con el frame buffer object
    fbo.begin();
    {
        ofClear(255);
    }
    fbo.end();
    texture = fbo.getTexture();

    font = game->getFont();

    nRandomCoins = (int)ofRandom(1, nMaxCoins + 1);

    bannerText(nRandomCoins);
}

void CrazyBow::update() {
    if (!canPass) {
        elapsedTime += ofGetLastFrameTime();
        if (elapsedTime > TIMER) {
            canPass = true;
            elapsedTime = 0;
        }
    }
}

void CrazyBow::draw() {
    transform.transformGL();
    {
        material.begin();
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
        material.end();

        texture.bind();
        {
            ofDrawPlane(0, boxCollider->getHeight() / 2 + nBlocksHigh * blockSize - BANNER_HEIGHT / 2, 0, BANNER_WIDTH, BANNER_HEIGHT);
        }
        texture.unbind();
    }
    transform.restoreTransformGL();
}

void CrazyBow::receiveCarCollision(Player* car) {
    if (canPass) {
        coinSound.play();
        car->addCoins(nRandomCoins);
        nRandomCoins = (int)ofRandom(1, nMaxCoins + 1);
        bannerText(nRandomCoins);
        canPass = false;
    }
}