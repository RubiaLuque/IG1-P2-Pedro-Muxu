#pragma once
#include "../Structure/GameObject.h"

class AreaRound : public GameObject {
private:
	ofNode* playerTransform;
	float playerSize;

public:
	AreaRound(Game* game, ofNode* playerTransform, float playerSize);

	virtual void update();

	// no se dibuja nada
	virtual void draw() { }

	virtual void receiveBombCollision(Bomb* bomb);
};