#pragma once
#include "../Structure/GameObject.h"

class AreaRound : public GameObject {
private:

public:
	AreaRound(Game* game, ofNode* playerTransform, glm::vec3 playerSize);

	// no se dibuja nada
	virtual void draw() { }

	virtual void receiveBombCollision(Bomb* bomb);
};