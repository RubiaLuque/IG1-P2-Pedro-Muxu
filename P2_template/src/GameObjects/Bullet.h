#pragma once
#include "../Structure/GameObject.h"
#include "Game.h"

class Bullet : public GameObject {
private:
	const float DEATH_TIMER = 5;
	// estático para que se pueda cargar antes
	static const int SIZE = 30;
	const int SPEED = 100;

	float elapsedTime;

	void timeToDeath();


public:
	Bullet(Game* game, glm::vec3 playerPos, glm::quat orientation);

	virtual void update();

	void drawDebug();

	void checkCollisions();

};