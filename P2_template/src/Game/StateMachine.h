#pragma once

#include "../Structure/State.h"

class StateMachine {
private:
    // la máquina de estados solo puede tener un único estado
    stack<State*> states;

protected:
    inline State* currentState() {
        return states.top();
    }

public:
    StateMachine() :states() { }

    ~StateMachine() {
        while (!states.empty()) {
            delete states.top();
            states.pop();
        }
    }

    // quitar el último estado
    void popState() {
        if (!states.empty()) {
            delete states.top();
            states.pop();
        }
    }

    // añadir un estado
    void pushState(State* s) {
        states.push(s);
        s->onEnter();
    }

    // cambiar el estado actual por otro
    void changeState(State* s) {
        if (!states.empty()) {
            // no se puede cambiar el estado por el mismo
            if (states.top()->getId() != s->getId()) {
                // se elimina el estado actual
                delete states.top();
                states.pop();

                states.push(s);
                s->onEnter();
            }
            // se elimina el estado que se había creado
            else {
                delete s;
            }
        }
    }

    void update() {
        currentState()->update();
    }
    void draw() {
        currentState()->draw();
    }
    void handleInput() {
        currentState()->handleInput();
    }
    void next() {
        currentState()->next();
    }

};