#ifndef PlayState_h
#define PlayState_h

#include "../Structure/State.h"
#include "Game.h"

class PlayState : public State {
private:

public:
    PlayState(Game* game) :State(game, ecs::_s_PLAY) { }

    virtual void onEnter();
    virtual void draw();
    virtual void next();
    virtual void handleInput();

};
#endif
