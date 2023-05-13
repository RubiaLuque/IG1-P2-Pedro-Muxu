#include "../Game/Game.h"

State::State(Game* game, ecs::stateId id) : game(game), id(id) {
    // se resetea el contenedor gameobjects del estado
    game->reset(id);
    ofLogNotice() << "Creating state: " << getName();
};