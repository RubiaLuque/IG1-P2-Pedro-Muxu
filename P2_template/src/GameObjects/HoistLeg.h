#pragma once
#include "../Structure/GameObject.h"
#include "Player.h"
#include "HoistArm.h"

class HoistLeg : public GameObject {
private:


public:
	HoistLeg(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
		material.setDiffuseColor(ofColor::yellow);

		HoistArm* hoistArm = new HoistArm(game, &transform, boxCollider);
		game->addGameObject(hoistArm);
	}

	virtual void update() {
		transform.rotateDeg(1, 0, 2, 0);
	}

	virtual void receiveCarCollision(Player* car) {
		car->stop();
	}
};