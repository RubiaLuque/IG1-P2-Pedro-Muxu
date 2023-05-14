#ifndef Road_h
#define Road_h

#include "../Structure/GameObject.h"

class Road : public GameObject {
private:
    ofLight light;
    ofPlanePrimitive plane;

public:
    Road(Game* game, glm::vec3 pos, glm::vec3 dim);

    void draw() override;
    void drawDebug() override;
};

#endif /* Road_h */
