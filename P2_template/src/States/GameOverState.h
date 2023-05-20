#pragma once
#include "../Structure/State.h"
class GameOverState : public State
{
private:
    string gameOver;
public:
    GameOverState(Game* game) : State(game, ecs::_s_GAMEOVER) { };

    virtual void onEnter();
    virtual void draw();
    virtual void handleInput();
};

