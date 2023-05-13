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

public:
    State(Game* game, ecs::stateId id);/* : game(game), id(id) {
        ofLogNotice() << "Creating state: " << getName();
    };
    */

    virtual ~State() {
        ofLogNotice() << "Destroying state: " << getName();
    };

    inline string getName() const {
        return ecs::ToString(id);
    }

    inline ecs::stateId getId() const {
        return id;
    }

    // conceptualmente todas los métodos serían abstractos
    virtual void onEnter() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    // se llama cuando el estado ha terminado
    // se pasa al siguiente estado
    virtual void next() = 0;
    virtual void keyPressed(int key) {};
    virtual void keyReleased(int key) {};
};
