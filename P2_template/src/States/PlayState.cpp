#include "PlayState.h"
#include "ResultState.h"
#include "PauseState.h"
#include "Player.h"
#include "../Utils/checkML.h"
#include "../GameObjects/Text.h"

void PlayState::onEnter() {
    game->initGame();

    Text* text = new Text(game, glm::vec2(ofGetWidth() - 50, 50), 20, "Press space to stop", game->getFont(), ofColor::white);
    text->setOrigin(glm::vec2(1, 0));
    game->addGameObject(text);
}
    
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

    State::draw();
};

void PlayState::next() {
    game->saveTime();
    game->changeState(new ResultState(game));
};


void PlayState::handleInput() {
    State::handleInput();

    // intercambiar entre el modo debug y el normal
    if (ofGetKeyPressed('d')) {
        game->toggleDebug();
    }
    // pausar el juego
    else if (ofGetKeyPressed(game->OF_KEY_SPACE)) {
        game->pushState(new PauseState(game));
    }
}
