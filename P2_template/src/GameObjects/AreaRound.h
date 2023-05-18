#pragma once
#include "../Structure/GameObject.h"

class AreaRound : public GameObject {
private:
	ofNode* playerTransform;

public:
	AreaRound(Game* game, ofNode* playerTransform, float playerSize) :
		GameObject(game, playerTransform->getGlobalPosition(), glm::vec3(playerSize * 2.5, playerSize / 3, playerSize * 2.5)),
		playerTransform(playerTransform) {
		transform.setGlobalOrientation(playerTransform->getGlobalOrientation());
	}

	virtual void update() {
		transform = *playerTransform;
	}

	// no se dibuja nada
	virtual void draw() { }
};