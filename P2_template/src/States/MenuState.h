#ifndef MenuState_h
#define MenuState_h

#include "../Structure/State.h"
#include "Game.h"

class MenuState : public State {
public:
    const int OFFSET = 100;

    MenuState(Game* game) : State(game, ecs::_s_MAIN_MENU) { };

    virtual void onEnter();
    virtual void draw();
    virtual void next();
};
#endif 
