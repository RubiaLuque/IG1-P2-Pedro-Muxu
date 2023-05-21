#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "../Structure/GameObject.h"
#include "ofxAssimpModelLoader.h"
class Game;

class Player : public GameObject {
private:
    const int MAX_SPEED = 2500;
    const int BULLET_TIMER = 1;
    const float SPEED_VARIATION = 5;
    const float ROTATION_VARIATION = 1;
    const float GRAVITY = 9.81;
    const float GRAVITY_SCALE = 60;
    const float JUMPFORCE = 450;
    const float FALLING_TIMER = 2;
    const float SKIDDING_TIME = 0.4;
    const glm::vec3 CAR_DIM = { 300, 150, 100 };

    const string MODEL_PATH = "Car.dae";

    ofxAssimpModelLoader car;

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
    float skiddingTime;
    bool bulletFired;
    float rotation;
    bool inputActivated;
    glm::vec3 originalPos;
    float verticalSpeed;
    bool falling;
    bool skidding;
    int counter;

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

    void counterShot();

    void counterFalling();

    void counterSkidding();

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

    void skid();

    inline bool getFalling() const {
        return falling;
    }

    inline float getSpeed() const {
        return speed;
    }

    inline void setSpeed(float newSpeed) {
        speed = newSpeed;
    }

    inline void setSkidding(bool newSkidding) {
        skidding = newSkidding;
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

    inline void setCoins(int coins) {
        this->coins = coins;
    }
};

#endif 