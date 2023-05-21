#include "AreaRound.h"
#include "Bomb.h"
#include "../Game/Game.h"
#include "Player.h"

AreaRound::AreaRound(Game* game, ofNode* playerTransform, float playerSize) :
	GameObject(game, playerTransform->getGlobalPosition(), glm::vec3(playerSize * 4, playerSize / 3, playerSize * 4)) {
	transform.setParent(*playerTransform);
	transform.move(0, -playerSize / 2, 0);
}

void AreaRound::receiveBombCollision(Bomb* bomb) {
	bomb->kill();
	game->getPlayer()->turnBack();
}