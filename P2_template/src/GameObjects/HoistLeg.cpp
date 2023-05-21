#include "HoistLeg.h"
#include "Player.h"
#include "../Game/Game.h"

HoistLeg::HoistLeg(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::yellow);

	HoistArm* hoistArm = new HoistArm(game, &transform, boxCollider);
	game->addGameObject(hoistArm);
}

void HoistLeg::update() {
	transform.rotateDeg(1, 0, 2, 0);
}

void HoistLeg::receiveCarCollision(Player* car) {
	car->stop();
}
