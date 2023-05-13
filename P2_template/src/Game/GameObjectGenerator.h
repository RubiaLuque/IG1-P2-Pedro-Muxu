
#ifndef GameObjectGenerator_h
#define GameObjectGenerator_h

#include "ofMain.h"
class Game;

// Clase que se utiliza para crear los objetos del PlayState
class GameObjectGenerator{
private:
    // CONSTANTES CON LAS POSICIONES
    // tamaños de los muros de los lados
    const int W = 2000;
    const int L = 10000;

    Game *game;
    
public:
    GameObjectGenerator(Game *game);
    
    void generateWorld();
};


#endif
