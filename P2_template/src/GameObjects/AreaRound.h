#pragma once
#include "../Structure/GameObject.h"

class AreaRound : public GameObject {
private:

public:
	AreaRound(Game* game, ofNode* playerTransform, BoxCollider* playerCollider);

	// no se dibuja nada
	virtual void draw() { }

	virtual void receiveBombCollision(Bomb* bomb);
};