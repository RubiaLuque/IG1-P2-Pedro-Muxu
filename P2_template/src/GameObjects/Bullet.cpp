#include "Bullet.h"

void Bullet::timeToDeath() {
	elapsedTime += ofGetLastFrameTime();
	if (elapsedTime > DEATH_TIMER) {
		kill();
		elapsedTime = 0;
	}
}


Bullet::Bullet(Game* game, glm::vec3 playerPos, glm::quat orientation) :
	GameObject(game, glm::vec3(playerPos.x, playerPos.y, playerPos.z), glm::vec3(SIZE)), elapsedTime(0) {

	material.setDiffuseColor(ofColor::lightBlue);
	transform.setGlobalOrientation(orientation);
}

void Bullet::update() {
	// mover el nodo a partir de la posición en la que se encontraba
	// se elije un eje a partir del que moverle
	transform.move(transform.getZAxis() * SPEED);
	timeToDeath();
}

void Bullet::drawDebug() {
	GameObject::drawDebug();

	transform.transformGL();
	{
		// tamaño de los axis
		ofDrawAxis(100);
	}
	transform.restoreTransformGL();
}

void Bullet::checkCollisions() {
	// se obtienen todos los objetos con los que ha colisionado
	vector<GameObject*> collisions = game->getCollisions(this);
	for (auto c : collisions) {
		// los objetos con los que ha colisionado hacen lo oportuno
		c->receiveBulletCollision(this);
	}
}