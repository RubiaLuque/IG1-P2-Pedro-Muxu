#ifndef ResultState_h
#define ResultState_h

#include "../Structure/State.h"

class Game;

class ResultState : public State {
public:
    ResultState(Game* game) : State(game, ecs::_s_RESULTS) { };

    ~ResultState();

    virtual void onEnter() { }
    void update();
    void draw();
    void next();
};

#endif /* ResultState_h */
