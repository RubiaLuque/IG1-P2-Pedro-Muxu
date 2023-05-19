#pragma once
#include "../Structure/GameObject.h"

class CrazyBow : public GameObject {
private:
    const int TIMER = 5;

    int blockSize;
    int nBlocksLong;
    int nBlocksHigh;
    int nRandomCoins;
    int nMaxCoins;
    bool canPass;
    float elapsedTime;

public:
    CrazyBow(Game* game, glm::vec3 pos, glm::vec3 dim, int nBlocksLong, int nBlocksHigh, int blockSize, glm::vec4 rotation, int nMaxCoins);

    virtual void update();

    virtual void draw();

    virtual void receiveCarCollision(Player* car);
};