#include "HoistArm.h"
#include "Player.h"
#include "../Game/Game.h"

HoistArm::HoistArm(Game* game, ofNode* hoistLegTransform, BoxCollider* hoistLegCollider) :
	GameObject(game, glm::vec3(0, 0, 0), glm::vec3(hoistLegCollider->getWidth(), hoistLegCollider->getWidth(), 500)) {
	material.setDiffuseColor(ofColor::yellow);
	transform.setParent(*hoistLegTransform);
	transform.move(0, hoistLegCollider->getHeight() / 2, boxCollider->getDepth() / 2 - hoistLegCollider->getDepth() / 2);

	Lever* lever = new Lever(game, &transform, boxCollider);
	game->addGameObject(lever);
}

void HoistArm::receiveCarCollision(Player* car) {
	car->stop();
}