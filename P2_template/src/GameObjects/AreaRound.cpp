#include "AreaRound.h"
#include "Bomb.h"
#include "../Game/Game.h"
#include "Player.h"

AreaRound::AreaRound(Game* game, ofNode* playerTransform, BoxCollider* playerCollider) :
	GameObject(game, glm::vec3(0, 0, 0),
		glm::vec3(playerCollider->getWidth() * 4, playerCollider->getHeight() / 3, playerCollider->getDepth() * 2)) {
	transform.setParent(*playerTransform);
	transform.move(0, -playerCollider->getHeight() / 2, 0);
}

void AreaRound::receiveBombCollision(Bomb* bomb) {
	bomb->kill();
	game->getPlayer()->turnBack();
}