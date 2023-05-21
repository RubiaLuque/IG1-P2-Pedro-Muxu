#pragma once
#include "../Structure/GameObject.h"
#include "HoistArm.h"

class HoistLeg : public GameObject {
private:


public:
	HoistLeg(Game* game, glm::vec3 pos, glm::vec3 dim);

	virtual void update();

	virtual void receiveCarCollision(Player* car);
};