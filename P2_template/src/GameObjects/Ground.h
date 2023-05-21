#pragma once
#include "../Structure/GameObject.h"
#include "Player.h"

class Ground : public GameObject {
private:
	const float PLAYER_MIN_SPEED = 200;

	float playerSpeedReduction;
	ofTexture groundTexture;
	ofPlanePrimitive plane;

public:
	Ground(Game* game, glm::vec3 pos, glm::vec3 dim, float playerSpeedReduction);

	virtual void draw();

	virtual void receiveCarCollision(Player* car);
};