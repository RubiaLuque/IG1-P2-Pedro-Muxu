#pragma once

#include "../Structure/State.h"
#include "Game.h"

class PauseState : public State {
public:
    PauseState(Game* game) : State(game, ecs::_s_PAUSE) { };

    virtual void onEnter() { }
    virtual void update() { }
    virtual void draw();
    virtual void next() { }
    virtual void keyPressed(int key);
};
