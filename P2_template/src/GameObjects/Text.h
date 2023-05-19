#pragma once
#include "../Structure/GameObject.h"

class Text : public GameObject {
protected:
	string text;
	glm::vec2 pos;
	ofColor color;
	glm::vec2 offset;
	int size;
	ofTrueTypeFont font;

	void show();

public:
	Text(Game* game, glm::vec2 pos, int size, string text, ofTrueTypeFont font, ofColor color);

	void setOrigin(glm::vec2 origin);

	virtual void draw();

	virtual void drawDebug();
};