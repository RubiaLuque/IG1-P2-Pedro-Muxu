#pragma once

#ifndef Blockage_h
#define Blockage_h

#include "../Structure/GameObject.h"

class Blockage : public GameObject {
private:

public:
	Blockage(Game* game, glm::vec3 pos, glm::vec3 dim);

	void receiveCarCollision(Player* car) override;
};
#endif //Blockage.h

