#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "../Structure/GameObject.h"
class Game;

class Player : public GameObject {
private:
    const int MAX_SPEED = 2500;
    const int BULLET_TIMER = 1;
    const float SPEED_VARIATION = 5;
    const float ROTATION_VARIATION = 1;
    static const int SIZE = 100;
    const float GRAVITY = 9.81;
    const float GRAVITY_SCALE = 60;
    const float JUMPFORCE = 450;
    const float FALL_OFFSET = 2;
    const float FALLING_TIMER = 3;

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
    float fallingTime;
    bool bulletFired;
    float rotation;
    bool inputActivated;
    glm::vec3 originalPos;
    float verticalSpeed;
    bool falling;

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

    void move();

    void continuousInput();

    void jump();

    inline bool isOnGround() const {
        return transform.getPosition().y <= originalPos.y;
    }

public:
    Player(Game* game, glm::vec3 pos);

    void update() override;
    void draw() override;
    void drawDebug() override;
    void handleInput() override;
    void checkCollisions() override;
    void fall();

    inline bool getFalling() const {
        return falling;
    }

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

    inline bool getInputActivated() const {
        return inputActivated;
    }

    inline void setInputActivated(bool enable) {
        inputActivated = enable;
    }

    inline void resetPos() {
        transform.setPosition(originalPos);
        transform.setOrientation(glm::vec3(0, 0, 0));
        speed = 0;
    }

    inline void turnBack() {
        transform.rotateDeg(180, 0, 1, 0);
    }

    inline void reduceSpeed(float reduction) {
        speed -= reduction;
    }
};

#endif 