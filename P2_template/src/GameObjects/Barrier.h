#pragma once

#ifndef Barrier_h
#define Barrier_h

#include "../Structure/GameObject.h"

class Barrier : public GameObject {
private:
	const float UPDOWN_TIME = 2;
	const float TOTAL_TIME = 4;
	const float OFFSET = 200;
	float bTime;

public:
	Barrier(Game* game, glm::vec3 pos, glm::vec3 dim);

	virtual void update();
	void receiveCarCollision(Player* car) override;
	void receiveBulletCollision(Bullet* bullet) override;

};
#endif

