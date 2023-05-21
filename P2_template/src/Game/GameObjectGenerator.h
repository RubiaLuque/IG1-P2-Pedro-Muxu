
#ifndef GameObjectGenerator_h
#define GameObjectGenerator_h

#include "ofMain.h"
class Game;

// Clase que se utiliza para crear los objetos del PlayState
class GameObjectGenerator{
private:
    // CONSTANTES CON LAS POSICIONES
    // tamaños de los muros de los lados
    const int WIDTH_ROAD = 2000;
    const int LENGTH_ROAD = 10000;
    const int WALL_SIZE = 100;
    const float OFFSET_Y = -50.1;
    const int HEIGHT_GOAL = 500;
    const int SIZE_GOAL_BARS = 50;
    const int HEIGHT_BOW = 300;
    const int HEIGHT_COIN = 25;
    const int RADIUS_COIN = 75;

    Game *game;
    
public:
    GameObjectGenerator(Game *game);
    
    void generateWorld();
};
#endif
