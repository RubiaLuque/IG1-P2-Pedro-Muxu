#include "AreaRound.h"
#include "Bomb.h"
#include "../Game/Game.h"
#include "Player.h"

AreaRound::AreaRound(Game* game, ofNode* playerTransform, float playerSize) :
	GameObject(game, playerTransform->getGlobalPosition(), glm::vec3(playerSize * 4, playerSize / 3, playerSize * 4)),
	playerTransform(playerTransform), playerSize(playerSize) {
	transform.setGlobalOrientation(playerTransform->getGlobalOrientation());
}

void AreaRound::update() {
	transform = *playerTransform;
	glm::vec3 playerPos = playerTransform->getPosition();
	transform.setPosition(playerPos.x, playerPos.y - playerSize / 2, playerPos.z);
}

void AreaRound::receiveBombCollision(Bomb* bomb) {
	bomb->kill();
	game->getPlayer()->turnBack();
}