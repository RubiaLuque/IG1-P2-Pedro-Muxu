//
//  Coin.h
//  P2_template
//
//  Created by Miguel Valero Espada on 19/4/23.
//

#ifndef Coin_h
#define Coin_h
#include "../Structure/GameObject.h"
#include "ofxAssimpModelLoader.h"

class Coin : public GameObject {
private:
    const string MODEL_PATH = "Dollar.obj";
    const float SPEED_ROTATION = 0.8;

    int coinsToAdd;
    ofCylinderPrimitive cylinder;

public:
    Coin(Game* game, glm::vec3 pos, float height, float radius, int coinsToAdd);

    virtual void update();
    virtual void draw();
    void receiveCarCollision(Player* car) override;
};

#endif /* Coin_h */
