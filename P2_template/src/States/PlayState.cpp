#include "PlayState.h"
#include "ResultState.h"
#include "PauseState.h"
#include "Player.h"
#include "../Utils/checkML.h"

void PlayState::onEnter() {
    game->initGame();
}

void PlayState::update() {
    // INPUT DEL JUGADOR
    // movimiento
    // el input continuo es mejor procesarlo en el update
    if (ofGetKeyPressed(OF_KEY_LEFT)) {
        game->getPlayer()->steerLeft();
    }
    else if (ofGetKeyPressed(OF_KEY_RIGHT)) {
        game->getPlayer()->steerRight();
    }
    if (ofGetKeyPressed(OF_KEY_UP)) {
        game->getPlayer()->accelerate();
    }
    else if (ofGetKeyPressed(OF_KEY_DOWN)) {
        game->getPlayer()->brake();
    }

    game->updateGameObjects();
};
    
void PlayState::draw() {
    ofBackground(0);
    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        // nombre
        ofDrawBitmapString(getName(), 0, 0);
        ofTranslate(0, 20);
        // tiempo transcurrido desde la partida
        ofDrawBitmapString("Time: " + ofToString(game->getEllapsedTime(), 2), 0, 0);
        ofTranslate(0, 20);
        // velocidad
        ofDrawBitmapString("Speed: " + ofToString(game->getPlayer()->getSpeed(), 2), 0, 0);
        ofTranslate(0, 20);
        // monedad
        ofDrawBitmapString("Coins: " + ofToString(game->getPlayer()->getCoins(), 2), 0, 0);
    }
    ofPopMatrix();

    game->drawGameObjects();
};

void PlayState::next() {
    game->changeState(new ResultState(game));
    //game->setState(new ResultState(game));
};


void PlayState::keyPressed(int key){
    // el input se maneja fuera del gameobject
    // INPUT DEL JUGADOR
    // luces
    if (key == 'l') {
        game->getPlayer()->toggleLight();
    }

    // INPUT GENERAL
    // intercambiar entre el modo debug y el normal
    if (key == 'd') {
        game->toggleDebug();
    }
    else if (key == game->OF_KEY_SPACE) {
        game->pushState(new PauseState(game));
    }
}
