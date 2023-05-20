#include "OilSpill.h"
#include "../Game/Game.h"
#include "Player.h"

OilSpill::OilSpill(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	oilSpillTexture = game->getOilSpillTexture();
	oilSpillTexture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
}

void OilSpill::draw() {
	oilSpillTexture.bind();
	{
		boxCollider->draw();
	}
	oilSpillTexture.unbind();
}

void OilSpill::receiveCarCollision(Player* car) {
	car->setSkidding(true);
}
