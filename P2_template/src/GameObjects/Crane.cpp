#include "Crane.h"
#include "Player.h"

Crane::Crane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::yellow);

	//brazo de la grua
	arm.set(DIM_ARM.x, DIM_ARM.y, DIM_ARM.z);
	arm.setPosition(pos.x, dim.y + DIM_ARM.y / 2, DIM_ARM.z / 2);


	cable.set(DIM_CABLE.x, DIM_CABLE.y,DIM_CABLE.z);
	//cable.setPosition();

	//datos de la base
	dimBase = dim;
	posBase = pos;

	//cable, tiene el collider
	transform.setPosition(cable.getPosition());
	transform.setScale(cable.getScale());
}

void Crane::update() {

}

void Crane::draw() {
	material.begin();
	{
		//brazo
		arm.draw();
		//base
		ofDrawBox(posBase, dimBase.x, dimBase.y, dimBase.z);
		
		//cable = collider
		cable.draw();
	}
	material.end();
}

void Crane::receiveCarCollision(Player* car) {

}
