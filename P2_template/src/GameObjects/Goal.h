

#ifndef Goal_h
#define Goal_h
#include "../Structure/GameObject.h"

class Goal : public GameObject {
private:
    int sizeBars;

public:
    Goal(Game* game, glm::vec3 pos, glm::vec3 dim, int sizeBars);

    void draw() override;
    void receiveCarCollision(Player* car) override;
};

#endif /* Goal_h */
