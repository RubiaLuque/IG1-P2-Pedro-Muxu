#pragma once

#include "../Structure/State.h"
// no me deja meter checkML.h

class StateMachine {
private:
    // la m�quina de estados solo puede tener un �nico estado
    State* state;

protected:
    inline State* currentState() {
        return state;
    }

public:
    StateMachine() :state(nullptr) { }

    ~StateMachine() {
        delete state;
    }

    void setState(State* s) {
        auto prevState = state;
        state = s;
        state->onEnter();
        // si hab�a un estado previo, se destruye
        if (prevState != nullptr) {
            delete prevState;
        }
    }

    void update() {
        currentState()->update();
    }
    void draw() {
        currentState()->draw();
    }
    void next() {
        currentState()->next();
    }
    void keyPressed(int key) {
        currentState()->keyPressed(key);
    }
    void keyReleased(int key) {
        currentState()->keyReleased(key);
    }
};