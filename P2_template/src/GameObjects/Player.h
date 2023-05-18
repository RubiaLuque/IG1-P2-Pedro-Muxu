#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "../Structure/GameObject.h"
class Game;

// TODO add speed settings
// #define MAX_SPEED 100

class Player : public GameObject {
private:
    const int MAX_SPEED = 100;
    const int BULLET_TIMER = 5;
    const float SPEED_VARIATION = 0.1;
    const float ROTATION_VARIATION = 1;
    static const int SIZE = 100;

    // luz del coche
    ofLight faro;
    // velocidad del coche
    float speed;
    // saber si está activada la luz o no
    bool bLight;
    glm::vec3 prevPos;
    // número de monedas
    int coins;
    float elapsedTime;
    bool bulletFired;
    float rotation;

    // intercalar luces
    inline void toggleLight() {
        bLight = !bLight;
    }

    // girar izquierda
    inline void steerLeft() {
        // DUDA: ¿por qué se pone un 2?
        transform.rotateDeg(ROTATION_VARIATION, 0, 2, 0);
    }
    // girar derecha
    inline void steerRight() {
        transform.rotateDeg(-ROTATION_VARIATION, 0, 2, 0);
    }
    // acelerar
    inline void accelerate() {
        speed += SPEED_VARIATION;
    }
    // desacelerar
    inline void brake() {
        speed -= SPEED_VARIATION;
    }

public:
    Player(Game* game);

    void update() override;
    void draw() override;
    void drawDebug() override;
    void handleInput() override;
    void checkCollisions() override;

    inline float getSpeed() const {
        return speed;
    }

    // añadir monedas
    inline void addCoins(int n = 1) {
        coins += n;
    }
    // obtener monedas actuales
    inline int getCoins() const {
        return coins;
    }

    // parar en seco
    inline void stop() {
        speed = 0;
        transform.setPosition(prevPos);
    }
};

#endif 
