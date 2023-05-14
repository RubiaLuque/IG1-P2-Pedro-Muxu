#ifndef GameObject_h
#define GameObject_h

#include "ofMain.h"
#include "../Utils/iCollide.h"

class Game;
class Player;

// Clase abstracta
class GameObject : public iCollide {
public:
    friend Game;

protected:
    // mover al objeto
    ofNode transform;
    // dar color al objeto
    ofMaterial material;
    // marcar si está vivo o no para eliminarlo posteriormente
    bool bAlive;
    Game* game;
    // se utiliza para determinar si se detectan las colisione si se utiliza la librería de físicas
    // no es necesario utilizarlo, pero es para recargar menos al sistema
    bool fixed;

    // posición y dimensiones del collider
    GameObject(Game* game, glm::vec3 pos, glm::vec3 dim);

public:

    // de forma predeterminada dibujar el collider, es decir, el cubo
    // redefinir si interes que el collider no coincida con lo que se muestra
    virtual void draw();
    virtual void drawDebug();
    // conceptualmente deberían ser virtuales puro, pero como no todos los objetos los van a
    // utilizar, se les establece solo como virtuales
    virtual void update() {};
    virtual void checkCollisions() {};
    // el input lo procesan los propios objetos
    virtual void handleInput() {}

    inline bool isAlive() const {
        return bAlive;
    }

    inline void kill() {
        bAlive = false;
    }

    inline bool isFixed() const {
        return fixed;
    }
};

#endif 
