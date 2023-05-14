#pragma once


#ifndef Person_h
#define Person_h

#include "../Structure/GameObject.h"

#include "ofxAssimpModelLoader.h"

class Pedestrian : public GameObject {
private:
    float speed;
    bool bTurned;
    string modelPath;
    ofxAssimpModelLoader model;

public:
    Pedestrian(Game* game, glm::vec3 pos, glm::vec3 dim);

    virtual void update();
    void draw() override;
    void receiveCarCollision(Player* car) override;
    //void receiveBulletCollision(GameObject* bullet) override;

    //void checkCollisions() override;
    void turn();
};
#endif /* Person_h */