#pragma once
#include "HoistArm.h"

class Lever : public GameObject {
private:
	const int TIMER = 5;

	float increment;
	float elapsedTime;

public:
	Lever(Game* game, ofNode* hoistArmTransform, BoxCollider* hoistArmCollider);

	virtual void update();

	virtual void receiveCarCollision(Player* car);
};