#pragma once
#include "GameObject.h"
class DeadlyTile : public GameObject
{
private:
	ofTexture warningTexture;
public:
	DeadlyTile(Game* game, glm::vec3 pos, glm::vec3 dim);
	void draw() override;
	void receiveCarCollision(Player* car) override;
};

