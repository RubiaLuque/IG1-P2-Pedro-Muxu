#pragma once

#include "ofMain.h"
#include "Game.h"
#include "../Structure/State.h"

class ofApp : public ofBaseApp {
private:
	Game* game;

public:
	virtual ~ofApp() {
		delete game;
	}

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
};
