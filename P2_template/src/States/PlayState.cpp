#include "PlayState.h"
#include "ResultState.h"
#include "PauseState.h"
#include "Player.h"
#include "../Utils/checkML.h"
#include "../GameObjects/Text.h"
#include "../GameObjects/DescendingText.h"

void PlayState::onEnter() {
    game->initGame();

    Text* text = new Text(game, glm::vec2(ofGetWidth() - 50, 50), 20, "Press p to stop", game->getFont(), ofColor::white);
    text->setOrigin(glm::vec2(1, 0));
    game->addGameObject(text);

    vector<ofColor> colors = { ofColor::red, ofColor::orange, ofColor::yellow, ofColor::green, ofColor::blue };
    DescendingText* descendingText = new DescendingText(game, glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2), 80, 10, 5, game->getFont(), colors);
    descendingText->setOrigin(glm::vec2(0.5, 0.5));
    game->addGameObject(descendingText);
}
    
void PlayState::draw() {
    ofBackground(0);

    State::draw();

    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        // Fps
        ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        // Nombre
        ofDrawBitmapString(getName(), 0, 0);
        ofTranslate(0, 20);
        // Tiempo
        ofDrawBitmapString("Time: " + ofToString(game->getEllapsedTime(), 2), 0, 0);
        ofTranslate(0, 20);
        // Velocidad
        ofDrawBitmapString("Speed: " + ofToString(game->getPlayer()->getSpeed(), 2), 0, 0);
        ofTranslate(0, 20);
        // Monedas
        ofDrawBitmapString("Coins: " + ofToString(game->getPlayer()->getCoins(), 2), 0, 0);
    }
    ofPopMatrix();
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
    else if (ofGetKeyPressed('p')) {
        game->pushState(new PauseState(game));
    }
}
