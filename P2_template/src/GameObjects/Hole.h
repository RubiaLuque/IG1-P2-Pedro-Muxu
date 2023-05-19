#pragma once
#include "../Structure/GameObject.h"

class Hole : public GameObject {
private:

public:
	Hole(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {}

	virtual void draw() {}

	virtual void receiveCarCollision(Player* car);
};