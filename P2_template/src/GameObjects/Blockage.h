#pragma once

#ifndef Blockage_h
#define Blockage_h

#include "GameObject.h"

class Blockage : public GameObject
{
public:
	Blockage(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Blockage();

	void update() override;
	void draw() override;
	void drawDebug() override;
	void receiveCarCollision(Player* car) override;

};
#endif //Blockage.h

