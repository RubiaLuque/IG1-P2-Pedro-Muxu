#pragma once
#include "HoistArm.h"

class Lever : public GameObject {
private:
	const int TIMER = 5;

	float increment;
	float elapsedTime;

public:
	Lever(Game* game, ofNode* hoistArmTransform, BoxCollider* hoistArmCollider) :
		GameObject(game, glm::vec3(0, 0, 0), glm::vec3(hoistArmCollider->getWidth() / 2.5, 100, hoistArmCollider->getWidth() / 2.5)),
		elapsedTime(0), increment(1.5) {

		material.setDiffuseColor(ofColor::grey);
		transform.setParent(*hoistArmTransform);
		transform.move(0, -boxCollider->getHeight() / 2, hoistArmCollider->getDepth() / 2 - boxCollider->getDepth());
	}

	virtual void update() {
		elapsedTime += ofGetLastFrameTime();

		boxCollider->setHeight(boxCollider->getHeight() + increment);
		transform.move(0, -increment / 2, 0);

		if (elapsedTime > TIMER) {
			elapsedTime = 0;
			increment = -increment;
		}
	}

	virtual void receiveCarCollision(Player* car) {
		car->stop();
		car->setCoins(0);
	}
};