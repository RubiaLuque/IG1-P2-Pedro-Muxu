#ifndef PlayState_h
#define PlayState_h

#include "../Structure/State.h"
#include "Game.h"

class PlayState : public State {
public:
    PlayState(Game* game) :State(game, ecs::_s_PLAY) { }

    ~PlayState() {};

    virtual void onEnter();
    virtual void update();
    virtual void draw();
    virtual void next();
    virtual void keyPressed(int key);

};
#endif
