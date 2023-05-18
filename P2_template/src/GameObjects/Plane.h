#pragma once
#include "ofxAssimpModelLoader.h"
#include "../Structure/GameObject.h"

class Plane : public GameObject {
private:
	const string MODEL_PATH = "Heli_bell.fbx";

		ofxAssimpModelLoader model;

public:
	Plane(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {

		assert(model.loadModel(MODEL_PATH));
		model.setRotation(0, -180, 1, 0, 0);
	}

	virtual void update() {
		model.update();
	}

	virtual void draw() {
		ofDisableArbTex();
		transform.transformGL();
		{
			model.drawFaces();
		}
		transform.restoreTransformGL();
	}
};