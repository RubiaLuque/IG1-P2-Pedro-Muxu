#pragma once

#ifndef WELL_H
#define WELL_H

#include "../Structure/GameObject.h"
// POZO
class Well : public GameObject {
private:
	ofMaterial circle;
	ofBoxPrimitive circleColl;

public:
	Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius);

	virtual void update();
	virtual void draw();
	virtual void recieveCarCollision(Player* car);
	void onTriggerEnter(Player* car);
};
#endif

