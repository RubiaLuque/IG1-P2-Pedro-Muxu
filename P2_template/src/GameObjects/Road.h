#ifndef Road_h
#define Road_h

#include "../Structure/GameObject.h"

class Road : public GameObject {
private:
    ofLight light;
    ofPlanePrimitive plane;

    void enableLight(bool enable, glm::vec2 roadCenter);

public:
    Road(Game* game, glm::vec3 pos, glm::vec3 dim, bool lightEnabled = true);

    virtual void draw() override;

    virtual void drawDebug() override;
};

#endif /* Road_h */
