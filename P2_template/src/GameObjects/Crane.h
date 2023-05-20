#pragma once
#include "GameObject.h"
class Crane: public GameObject
{
	//El boxPrimmitive que hereda de gameObject es la base de la grua
	//Las otras dos partes movibles son atributos de esta clase
private:
	const glm::vec3 DIM_ARM = {600, 50, 50};
	const glm::vec3 DIM_CABLE = {20, 300, 20};

	glm::vec3 dimBase;
	glm::vec3 posBase;

	ofBoxPrimitive arm;
	ofBoxPrimitive cable;

public:
	Crane(Game* game, glm::vec3 pos, glm::vec3 dim);
	void draw() override;
	void update() override;
	void receiveCarCollision(Player* car) override;
};

