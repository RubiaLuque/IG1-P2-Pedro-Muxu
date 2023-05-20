#pragma once


#ifndef Person_h
#define Person_h

#include "../Structure/GameObject.h"
#include "ofxAssimpModelLoader.h"
#include "../Game/Game.h"

class Pedestrian : public GameObject {
private:
    const string MODEL_PATH = "astroBoy_walk.dae";
    const int SPEED = 300;
    const int COINS = 100;

    ofxAssimpModelLoader model;

public:
    Pedestrian(Game* game, glm::vec3 pos, float height, glm::vec4 rotation);

    virtual void update();
    void draw() override;
    virtual void checkCollisions();
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(Bullet* bullet) override;

    void turnBack();
};

#endif /* Person_h */