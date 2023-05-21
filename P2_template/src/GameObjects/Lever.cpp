#include "Lever.h"
#include "Player.h"
#include "../Game/Game.h"

Lever::Lever(Game* game, ofNode* hoistArmTransform, BoxCollider* hoistArmCollider) :
	GameObject(game, glm::vec3(0, 0, 0), glm::vec3(hoistArmCollider->getWidth() / 2.5, 100, hoistArmCollider->getWidth() / 2.5)),
	elapsedTime(0), increment(1.5) {

	material.setDiffuseColor(ofColor::grey);
	transform.setParent(*hoistArmTransform);
	transform.move(0, -boxCollider->getHeight() / 2, hoistArmCollider->getDepth() / 2 - boxCollider->getDepth());
}

void Lever::update() {
	elapsedTime += ofGetLastFrameTime();

	boxCollider->setHeight(boxCollider->getHeight() + increment);
	transform.move(0, -increment / 2, 0);

	if (elapsedTime > TIMER) {
		elapsedTime = 0;
		increment = -increment;
	}
}

void Lever::receiveCarCollision(Player* car) {
	car->stop();
	if (car->getCoins() > 0) {
		ofSoundPlayer drop = game->getSound(ecs::_sound_COIN_DROP);
		drop.play();
		car->setCoins(0);
	}
}