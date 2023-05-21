#include "AreaRound.h"
#include "Bomb.h"
#include "../Game/Game.h"
#include "Player.h"

AreaRound::AreaRound(Game* game, ofNode* playerTransform, glm::vec3 playerSize) :
	GameObject(game, glm::vec3(0, 0, 0), glm::vec3(playerSize.x * 4, playerSize.y / 3, playerSize.z * 4)) {
	transform.setParent(*playerTransform);
	transform.move(0, -playerSize.y / 2, 0);
}

void AreaRound::receiveBombCollision(Bomb* bomb) {
	bomb->kill();
	game->getPlayer()->turnBack();
}