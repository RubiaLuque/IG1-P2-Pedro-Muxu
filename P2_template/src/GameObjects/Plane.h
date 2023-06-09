#pragma once
#include "ofxAssimpModelLoader.h"
#include "../Structure/GameObject.h"

class Plane : public GameObject {
private:
	// no tiene animaciones
	const string MODEL_PATH = "aircraft.obj";
	// mitad del lado del cubo que se utiliza para comprobar si el avi�n
	// ha llegado a cierto punto
	const int OFFSET = 10;
	const int SPEED = 300;
	const int BOMB_TIMER = 5;

	ofxAssimpModelLoader model;
	glm::vec3 start;
	glm::vec3 end;
	glm::vec3 pointToReach;
	float elapsedTime;
	float limitY;

	bool hasReachedPoint();

	glm::vec3 direction();

public:
	Plane(Game* game, glm::vec3 start, glm::vec3 end, float height, float limitY);

	virtual void draw();

	virtual void update();

	virtual void receiveCarCollision(Player* car);
};