#pragma once

#ifndef Barrier_h
#define Barrier_h

#include "GameObject.h"

class Barrier : public GameObject
{
private: 
	const float UPDOWN_TIME = 2;
	const float TOTAL_TIME = 4;
	float bTime;
	const float OFFSET = 2;
	bool up;

	struct {
		float x, y, z;
	} position;

public: 
	Barrier(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Barrier();

	virtual void update();
	virtual void draw();
	void drawDebug() override;
	void receiveCarCollision(Player* car) override;

};
#endif

