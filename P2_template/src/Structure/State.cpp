#include "../Game/Game.h"

State::State(Game* game, ecs::stateId id) : game(game), id(id) {
    // se resetea el contenedor gameobjects del estado
    game->reset(id);
    ofLogNotice() << "Creating state: " << getName();

    clickSound.load(CLICK_SOUND_PATH);
    assert(clickSound.isLoaded());
};

void State::update() {
    game->updateGameObjects();
}

void State::draw() {
    game->drawGameObjects();
}

void State::handleInput() {
    game->handleInputGameObjects();
}