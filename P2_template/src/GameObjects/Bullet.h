#pragma once
#include "../Structure/GameObject.h"
#include "Game.h"

class Bullet : public GameObject {
private:
	const float DEATH_TIMER = 10;
	// estático para que se pueda cargar antes
	static const int SIZE = 30;
	const int SPEED = 45;

	float elapsedTime;

	void timeToDeath() {
		elapsedTime += ofGetLastFrameTime();
		if (elapsedTime > DEATH_TIMER) {
			kill();
			elapsedTime = 0;
		}
	}


public:
	Bullet(Game* game, glm::vec3 playerPos, float offset, glm::quat orientation) :
		GameObject(game, glm::vec3(playerPos.x, playerPos.y + offset / 2, playerPos.z), glm::vec3(SIZE)), elapsedTime(0) {

		material.setDiffuseColor(ofColor::lightBlue);
		transform.setGlobalOrientation(orientation);
	}

	virtual void update() {
		// mover el nodo a partir de la posición en la que se encontraba
		// se elije un eje a partir del que moverle
		transform.move(transform.getZAxis() * SPEED);
		timeToDeath();
	}

	void drawDebug() {
		GameObject::drawDebug();

		transform.transformGL();
		{
			// tamaño de los axis
			ofDrawAxis(100);
		}
		transform.restoreTransformGL();
	}

	void checkCollisions() {
		// se obtienen todos los objetos con los que ha colisionado
		vector<GameObject*> collisions = game->getCollisions(this);
		for (auto c : collisions) {
			// los objetos con los que ha colisionado hacen lo oportuno
			c->receiveBulletCollision(this);
		}
	}

};