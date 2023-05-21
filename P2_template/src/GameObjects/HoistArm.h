#pragma once
#include "HoistLeg.h"
#include "Lever.h"

class HoistArm : public GameObject {
private:


public:
	HoistArm(Game* game, ofNode* hoistLegTransform, BoxCollider* hoistLegCollider);

	virtual void receiveCarCollision(Player* car);
};