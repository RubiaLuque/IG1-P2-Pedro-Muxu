#pragma once

#include "GameObject.h"
class OilSpill : public GameObject
{
private:
	ofTexture oilSpillTexture;

public:
	OilSpill(Game* game, glm::vec3 pos, glm::vec3 dim);

	virtual void draw();

	virtual void receiveCarCollision(Player* car);
};

