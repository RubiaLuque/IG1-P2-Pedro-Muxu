#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"
#include "../Utils/checkML.h"
 
//ResultState::ResultState(Game* game) : State(game, ecs::_s_RESULTS) { };

ResultState::~ResultState() {};

void ResultState::update() {
    game->updateGameObjects();
};

void ResultState::draw() {
    ofBackground(127);
    ofDrawBitmapString(getName(), 10, 20);
    game->drawGameObjects();
};

void ResultState::next() {
    game->setState(new MenuState(game));
};