#ifndef Wall_h
#define Wall_h

#include "../Structure/GameObject.h"

class Wall : public GameObject {
private:

public:
    Wall(Game* game, glm::vec3 pos, glm::vec3 dim);

    void receiveCarCollision(Player* car) override;

    void receiveBulletCollision(Bullet* bullet) override;

    virtual void receivePedestrianCollision(Pedestrian* pedestrian);
};

#endif

