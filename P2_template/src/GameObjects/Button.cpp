#include "Button.h"
#include "../Game/Game.h"

void Button::show() {
	ofPushStyle();
	ofPushMatrix();
	{
		// de abajo a arriba
		// las transformaciones se añaden unas a otras
		// afecta tanto al rectángulo como al texto

		// posición general
		ofTranslate(pos.x + offset.x, pos.y + offset.y);

		// rectángulo
		ofPushMatrix();
		{
			ofTranslate(-widen.x / 2, -widen.y / 2);
			ofScale(game->getSizeRatio(size));
			// interior
			ofSetColor(buttonColors[currentState]);
			ofDrawRectangle(boundingBox);
			// borde
			ofNoFill();
			ofSetColor(textColor);
			ofDrawRectangle(boundingBox);
		}
		ofPopMatrix();

		// afecta solo al texto
		ofScale(game->getSizeRatio(size));
		ofSetColor(textColor);
		font.drawString(text, 0, 0);
	}
	ofPopMatrix();
	ofPopStyle();
}

bool Button::mouseIsOnRect() {
	// posición real de la caja
	glm::vec2 boxPos = glm::vec2(game->convertToProperSize<float>(boundingBox.x, size) + pos.x + offset.x - widen.x / 2,
		game->convertToProperSize<float>(boundingBox.y, size) + pos.y + offset.y - widen.y / 2);
	// tamaño real de la caja
	float boxWidth = game->convertToProperSize<float>(boundingBox.width, size);
	float boxHeight = game->convertToProperSize<float>(boundingBox.height, size);

	glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
	return mousePos.x > boxPos.x && mousePos.x < boxPos.x + boxWidth &&
		mousePos.y > boxPos.y && mousePos.y < boxPos.y + boxHeight;
}

Button::Button(Game* game, glm::vec2 pos, float size, ofTrueTypeFont font, string text, ofColor textColor, array<ofColor, 3> buttonColors, glm::vec2 widen, std::function<void()> callback) :
	GameObject(game, glm::vec3(pos, 0), glm::vec3(size)), pos(pos), size(size), textColor(textColor), released(true),
	buttonColors(buttonColors), text(text), offset(glm::vec2(0, 0)), widen(widen), currentState(MOUSE_OUT),
	callback(callback), font(font) {
	isUI = true;

	boundingBox = this->font.getStringBoundingBox(text, 0, 0);
	boundingBox.width += widen.x;
	boundingBox.height += widen.y;

	// ensanchamiento real de la caja
	this->widen = game->convertToProperSize<glm::vec2>(widen, size);
}

void Button::setOrigin(glm::vec2 origin) {
	offset = glm::vec2(-font.stringWidth(text) * origin.x, -font.stringHeight(text) * origin.y);
	offset = game->convertToProperSize<glm::vec2>(offset, size);
}

void Button::draw() {
	show();
}

void Button::drawDebug() {
	show();
}

void Button::update() {
	if (mouseIsOnRect()) {
		currentState = MOUSE_OVER;
		if (ofGetMousePressed(0) && released) {
			released = false;
			currentState = CLICKED;
			callback();
		}
		else if (!ofGetMousePressed(0)) {
			released = true;
		}
	}
	else {
		currentState = MOUSE_OUT;
	}
}