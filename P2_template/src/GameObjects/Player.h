#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "../Structure/GameObject.h"
class Game;

// TODO add speed settings
// #define MAX_SPEED 100

class Player : public GameObject{
private:
    const int MAX_SPEED = 100;

    // luz del coche
    ofLight faro;
    // velocidad del coche
    float speed;
    // saber si está activada la luz o no
    bool bLight;
    glm::vec3 prevPos;
    // número de monedas
    int coins;
    
public:
    
    Player(Game *game);
    ~Player();
    
    void update() override;
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
    // creo que no se usa
    float getSpeed();
    // girar izquierda
    void steerLeft();
    // girar derecha
    void steerRight();
    // acelerar
    void accelerate();
    // intercalar luces
    void toggleLight();
    // desacelerar
    void brake();
    // parar en seco
    void stop();
    // añadir monedas
    void addCoins(int n = 1);
    // obtener monedas actuales
    int getCoins();
    
};

#endif 
