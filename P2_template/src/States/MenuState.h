#ifndef MenuState_h
#define MenuState_h

#include "../Structure/State.h"
#include "Game.h"

class MenuState : public State {
public:
    MenuState(Game* game) : State(game, ecs::_s_MAIN_MENU) { };

    ~MenuState() {};

    virtual void onEnter() { }
    virtual void update();
    virtual void draw();
    virtual void next();

};
#endif 
