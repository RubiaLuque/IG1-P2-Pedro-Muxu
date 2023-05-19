#include "Plane.h"
#include "Player.h"
#include "Bomb.h"
#include "../Game/Game.h"

bool Plane::hasReachedPoint() {
	glm::vec3 actPos = transform.getPosition();
	return actPos.x < pointToReach.x + OFFSET && actPos.x > pointToReach.x - OFFSET &&
		actPos.y < pointToReach.y + OFFSET && actPos.y > pointToReach.y - OFFSET &&
		actPos.z > pointToReach.z - OFFSET && actPos.z < pointToReach.z + OFFSET;
}

glm::vec3 Plane::direction() {
	glm::vec3 dir = end - start;
	// derecha
	if (dir.x < 0) {
		return transform.getXAxis();
	}
	// izquierda
	else if (dir.x > 0) {
		return -transform.getXAxis();
	}
	// hacia arriba
	else if (dir.y > 0) {
		return transform.getYAxis();
	}
	// hacia abajo
	else if (dir.y < 0) {
		return -transform.getYAxis();
	}
	// hacia atrás
	else if (dir.z < 0) {
		return -transform.getZAxis();
	}
	// hacia adelante
	else if (dir.z > 0) {
		return transform.getZAxis();
	}
	else {
		return glm::vec3(0, 0, 0);
	}
}

Plane::Plane(Game* game, glm::vec3 start, glm::vec3 end, float height, float limitY) :
	GameObject(game, start, glm::vec3(6 * height, height, 3 * height)), start(start), end(end), pointToReach(end),
	elapsedTime(0), limitY(limitY) {

	assert(model.loadModel(MODEL_PATH));
	model.setRotation(0, 180, 0, 0, 1);
	model.setScale(height / 100, height / 100, height / 100);

	boxCollider->move(glm::vec3(0, height, 0));

	glm::vec3 aux = end - start;
}

void Plane::draw() {
	transform.transformGL();
	{
		model.drawFaces();
	}
	transform.restoreTransformGL();
}

void Plane::update() {
	transform.move(direction() * SPEED * ofGetLastFrameTime());
	if (hasReachedPoint()) {
		transform.rotateDeg(-180, 0, 1, 0);
		if (pointToReach == start) {
			pointToReach = end;
		}
		else {
			pointToReach = start;
		}
	}

	elapsedTime += ofGetLastFrameTime();
	if (elapsedTime > BOMB_TIMER) {
		elapsedTime = 0;
		Bomb* bomb = new Bomb(game, transform.getGlobalPosition(), limitY);
		game->addGameObject(bomb);
	}
}

void Plane::receiveCarCollision(Player* car) {
	car->stop();
}