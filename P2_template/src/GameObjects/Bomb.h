#pragma once
#include "../Structure/GameObject.h"

class Bomb : public GameObject {
private:
	static const int SIZE = 40;
	const int SPEED = 100;

	float limitY;

public:
	Bomb(Game* game, glm::vec3 pos, float limitY);

	virtual void receiveCarCollision(Player* car);

	virtual void checkCollisions();

	virtual void update();

	void kill();
};