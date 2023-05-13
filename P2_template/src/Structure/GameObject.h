#ifndef GameObject_h
#define GameObject_h

#include "ofMain.h"
#include "../Utils/iCollide.h"

class Game;
class Player;

// Clase abstracta
class GameObject : public iCollide {

protected:
    // dar color al gameobject
    ofMaterial material;
    // marcar si está vivo o no para eliminarlo posteriormente
    bool bAlive;
    Game* game;

public:
    // mover al objeto
    ofNode transform;

    GameObject(Game* game, glm::vec3 pos);
    virtual ~GameObject();

    virtual void draw() = 0;
    virtual void drawDebug();
    // conceptualmente update y checkcollisions deberían ser
    // virtuales puro, pero como no todos los objetos los van a
    // utilizar, se les establece solo como virtuales
    virtual void update() {};
    virtual void checkCollisions() {};

    inline bool isAlive() const {
        return bAlive;
    }

    inline void kill() {
        bAlive = false;
    }
};

#endif 
