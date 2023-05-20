#include "Text.h"
#include "../Game/Game.h"

void Text::show() {
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

Text::Text(Game* game, glm::vec2 pos, int size, string text, ofTrueTypeFont font, ofColor color) :
	GameObject(game, glm::vec3(pos, 0), glm::vec3(size)), text(text), pos(pos), color(color), offset(0, 0), size(size), font(font) {
	isUI = true;
}

void Text::setOrigin(glm::vec2 origin) {
	offset = glm::vec2(-font.stringWidth(text) * origin.x, font.stringHeight(text) * origin.y);
	offset = game->convertToProperSize<glm::vec2>(offset, size);
}

void Text::draw() {
	show();
}

void Text::drawDebug() {
	show();
}