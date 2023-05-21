#include "PauseState.h"
#include "../Utils/checkML.h"
#include "../GameObjects/Text.h"

void PauseState::onEnter() {
    Text* text = new Text(game, glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2), 50, "Press p to continue", game->getFont(), ofColor::white);
    text->setOrigin(glm::vec2(0.5, 0.5));
    game->addGameObject(text);
}

void PauseState::draw() {
    ofBackground(0);
    ofDrawBitmapString(getName(), 10, 20);

    State::draw();
};

void PauseState::handleInput() {
    State::handleInput();

    // siempre se pone al final
    // porque sino se habrá eliminado el estado, pero quedará por ejecutar el handleInput de los gameobjects
    // y no se podrá hacer
    if (ofGetKeyPressed('p')) {
        clickSound.play();
        game->popState();
    }
}