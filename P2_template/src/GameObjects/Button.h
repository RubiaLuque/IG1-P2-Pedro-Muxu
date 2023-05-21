#pragma once
#include "../Structure/GameObject.h"

class Button : public GameObject {
private:
	enum States
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	glm::vec2 pos;
	glm::vec2 offset;
	int size;
	glm::vec2 widen;
	ofTrueTypeFont font;
	ofRectangle boundingBox;
	//std::function<void> callback;
	array<ofColor, 3> buttonColors;
	ofColor textColor;
	string text;
	States currentState;
	// se utiliza para evitar pulsar el botón otra vez
	// hasta que se haya dejado de clicar
	bool released;
	// función void sin parámetros
	std::function<void()> callback;
	ofSoundPlayer sound;

	void show();

	bool mouseIsOnRect();

public:
	Button(Game* game, glm::vec2 pos, float size, ofTrueTypeFont font, string text, ofColor textColor, array<ofColor, 3> buttonColors, glm::vec2 widen, std::function<void()> callback);

	void setOrigin(glm::vec2 origin);

	virtual void draw();

	virtual void drawDebug();

	virtual void update();
};