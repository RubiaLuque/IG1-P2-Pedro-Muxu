#pragma once

#include "ofMain.h"
#include "../Game/ecs_def.h"
class Game;

// Clase abstracta
class State {
protected:
    // id del estado
    ecs::stateId id;
    // puntero al juego
    Game* game;

    State(Game* game, ecs::stateId id);
public:

    virtual ~State() {
        ofLogNotice() << "Destroying state: " << getName();
    };

    inline string getName() const {
        return ecs::ToString(id);
    }

    inline ecs::stateId getId() const {
        return id;
    }

    virtual void onEnter() = 0;
    // updadte, draw y handleInput de todos los gameobjects que hay en el estado
    virtual void update();
    virtual void draw();
    virtual void handleInput();
    // se llama cuando el estado ha terminado
    // se pasa al siguiente estado
    virtual void next() { };
    /*
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    */
};
