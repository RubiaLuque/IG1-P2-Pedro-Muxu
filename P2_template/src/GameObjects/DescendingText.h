#pragma once
#include "Text.h"

class DescendingText : public Text {
private:
	const int TIMER = 2;
	float elapsedTime;
	int maxNumber;
	int actNumber;
	int decrease;
	vector<ofColor> colors;
	glm::vec2 origin;

public:
	DescendingText(Game* game, glm::vec2 pos, int maxSize, int decrease, int number, ofTrueTypeFont font, vector<ofColor>colors);

	virtual void update();

	void setOrigin(glm::vec2 origin);
};