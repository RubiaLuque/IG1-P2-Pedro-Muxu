#include "DeadlyTile.h"
#include "../Game/Game.h"
#include "Player.h"

DeadlyTile::DeadlyTile(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	warningTexture = game->getWarningTexture();
	warningTexture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
}

void DeadlyTile::draw() {
	warningTexture.bind();
	{
		boxCollider->draw();
	}
	warningTexture.unbind();
}

void DeadlyTile::receiveCarCollision(Player* car) {
	car->stop();
	ofSoundPlayer gameOver = game->getSound(ecs::_sound_GAMEOVER);
	gameOver.play();
	game->gameOver();
}
