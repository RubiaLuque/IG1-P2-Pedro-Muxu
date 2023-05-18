
#ifndef GameObjectGenerator_h
#define GameObjectGenerator_h

#include "ofMain.h"
class Game;

// Clase que se utiliza para crear los objetos del PlayState
class GameObjectGenerator{
private:
    // CONSTANTES CON LAS POSICIONES
    // tama�os de los muros de los lados
    const int WIDTH_ROAD = 2000;
    const int LENGTH_ROAD = 10000;
    const int WALL_SIZE = 100;
    const float OFFSET_Y = -50.1;

    Game *game;
    
public:
    GameObjectGenerator(Game *game);
    
    void generateWorld();
};
#endif
