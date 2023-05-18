#pragma once


#ifndef Person_h
#define Person_h

#include "../Structure/GameObject.h"
#include "ofxAssimpModelLoader.h"

class Pedestrian : public GameObject {
private:
    const string MODEL_PATH = "astroBoy_walk.dae";

    float speed;
    bool bTurned;
    ofxAssimpModelLoader model;

public:
    Pedestrian(Game* game, glm::vec3 pos, glm::vec3 dim);

    virtual void update();
    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(Bullet* bullet) override;

    void turn();
};
#endif /* Person_h */