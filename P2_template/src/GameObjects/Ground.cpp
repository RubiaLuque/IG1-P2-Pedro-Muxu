#include "Ground.h"
#include "../Game/Game.h"

Ground::Ground(Game* game, glm::vec3 pos, glm::vec3 dim, float playerSpeedReduction) :
	GameObject(game, pos, dim), playerSpeedReduction(playerSpeedReduction) {
	groundTexture = game->getGroundTexture();
	// establece como se escala la imagen hacia arriba y hacia abajo, cuando se dibuja
	// más pequeña (primer param) y más grande (segundo param)
	groundTexture.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
}

void Ground::draw() {
	groundTexture.bind();
	{
		boxCollider->draw();
	}
	groundTexture.unbind();
}

void Ground::receiveCarCollision(Player* car) {
	if (car->getSpeed() > PLAYER_MIN_SPEED) {
		car->reduceSpeed(playerSpeedReduction);
	}
}