#pragma once

#ifndef WELL_H
#define WELL_H

#include "../Structure/GameObject.h"
//Pozo
class Well : public GameObject
{
private:
	ofMaterial circle;
	ofBoxPrimitive circleColl;

public:
	Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius);
	~Well();

	virtual void update();
	virtual void draw();
	void drawDebug() override;
	virtual void recieveCarCollision(Player* car);
	void onTriggerEnter(Player* car);
};
#endif

