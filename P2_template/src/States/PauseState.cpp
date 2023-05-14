#include "PauseState.h"
#include "../Utils/checkML.h"

void PauseState::draw() {
    ofBackground(0);
    ofDrawBitmapString(getName(), 10, 20);

    State::draw();
};

void PauseState::handleInput() {
    State::handleInput();

    // siempre se pone al final
    // porque sino se habr� eliminado el estado, pero quedar� por ejecutar el handleInput de los gameobjects
    // y no se podr� hacer
    if (ofGetKeyPressed(game->OF_KEY_SPACE)) {
        game->popState();
    }
}