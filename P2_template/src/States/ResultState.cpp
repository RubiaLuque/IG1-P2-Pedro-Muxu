#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"
#include "../Utils/checkML.h"

void ResultState::draw() {
    ofBackground(127);
    ofDrawBitmapString(getName(), 10, 20);

    State::draw();
};

void ResultState::next() {
    game->changeState(new MenuState(game));
};