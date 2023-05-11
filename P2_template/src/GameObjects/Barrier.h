#pragma once

#ifndef Barrier_h
#define Barrier_h

#include "GameObject.h"

class Barrier : public GameObject
{
private: 
	const float UPDOWN_TIME = 300;
	const float TOTAL_TIME = 600;
	float bTime;
	int offset;
	bool up;

	struct {
		float x, y, z;
	} position;

public: 
	Barrier(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Barrier();

	void update() override;
	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player* car) override;

};
#endif

