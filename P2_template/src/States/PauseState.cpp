#include "PauseState.h"
#include "../Utils/checkML.h"

void PauseState::draw() {
    ofBackground(0);
    ofDrawBitmapString(getName(), 10, 20);
};

void PauseState::keyPressed(int key) {
    if (key == game->OF_KEY_SPACE) {
        game->popState();
    }
}