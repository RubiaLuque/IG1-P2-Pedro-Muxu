#pragma once
#include "HoistLeg.h"
#include "Lever.h"

class HoistArm : public GameObject {
private:


public:
	HoistArm(Game* game, ofNode* hoistLegTransform, BoxCollider* hoistLegCollider) :
		GameObject(game, glm::vec3(0, 0, 0), glm::vec3(hoistLegCollider->getWidth(), hoistLegCollider->getWidth(), 500)) {
		material.setDiffuseColor(ofColor::yellow);
		transform.setParent(*hoistLegTransform);
		transform.move(0, hoistLegCollider->getHeight() / 2, boxCollider->getDepth() / 2 - hoistLegCollider->getDepth() / 2);

		Lever* lever = new Lever(game, &transform, boxCollider);
		game->addGameObject(lever);
	}

	virtual void receiveCarCollision(Player* car) {
		car->stop();
	}
};