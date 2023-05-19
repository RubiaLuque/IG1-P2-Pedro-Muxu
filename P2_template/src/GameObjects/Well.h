#ifndef WELL_H
#define WELL_H

#include "../Structure/GameObject.h"
// POZO
class Well : public GameObject {
private:
	const int HEIGHT = 100;
	const int OFFSET = 50;
	float radius;

public:
	Well(Game* game, glm::vec3 pos, glm::vec3 dim, float radius_);

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
};
#endif

