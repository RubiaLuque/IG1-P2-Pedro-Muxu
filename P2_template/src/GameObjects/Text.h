#pragma once
#include "../Structure/GameObject.h"

class Text : public GameObject {
private:
	string text;
	glm::vec2 pos;
	ofColor color;
	glm::vec2 offset;
	int size;
	ofTrueTypeFont font;

	void show() {
		ofPushMatrix();
		ofPushStyle();
		{
			ofSetColor(color);
			ofTranslate(pos.x + offset.x, pos.y + offset.y);
			ofScale(game->getSizeRatio(size));
			font.drawString(text, 0, 0);
		}
		ofPopStyle();
		ofPopMatrix();
	}

public:
	Text(Game* game, glm::vec2 pos, int size, string text, ofTrueTypeFont font, ofColor color) :
		GameObject(game, glm::vec3(pos, 0), glm::vec3(size)), text(text), pos(pos), color(color), offset(0, 0), size(size), font(font) {
		isUI = true;
	}

	inline void setOrigin(glm::vec2 origin) {
		offset = glm::vec2(-font.stringWidth(text) * origin.x, -font.stringHeight(text) * origin.y);
		offset = game->convertToProperSize<glm::vec2>(offset, size);
	}

	virtual void draw() {
		show();
	}

	virtual void drawDebug() {
		show();
	}
};