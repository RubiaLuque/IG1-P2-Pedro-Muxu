#ifndef ResultState_h
#define ResultState_h

#include "../Structure/State.h"

class Game;

class ResultState : public State {
public:
    ResultState(Game* game) : State(game, ecs::_s_RESULTS) { }

    virtual void onEnter();
    virtual void draw();
    virtual void next();
};

#endif /* ResultState_h */
