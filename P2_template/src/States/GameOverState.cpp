#include "GameOverState.h"
#include "PlayState.h"
#include "../GameObjects/Text.h"
#include "../GameObjects/Button.h"
#include "../Game/Game.h"

void GameOverState::onEnter() {

	Text* text = new Text(game, glm::vec2(ofGetWidth() / 2, ofGetHeight() / 3), 150, "GAME OVER", game->getFont(), ofColor::mediumVioletRed);
	text->setOrigin(glm::vec2(0.5, 0.5));
	game->addGameObject(text);

	array<ofColor, 3> colors = { ofColor::red, ofColor::mediumVioletRed, ofColor::darkRed };
	Button* newGame = new Button(game, glm::vec2(ofGetWidth() / 2, 2 * ofGetHeight() / 3), 100, game->getFont(), "NEW GAME", ofColor::white, colors, glm::vec2(120, 70),
		[&] {
			
			game->changeState(new PlayState(game));
		});

	newGame->setOrigin(glm::vec2(0.5, 0.5));
	game->addGameObject(newGame);

	Text* text1 = new Text(game, glm::vec2(ofGetWidth() / 2, 6 * ofGetHeight() / 7), 50, "Press x to exit", game->getFont(), ofColor::ghostWhite);
	text1->setOrigin({ 0.5,0.5 });
	game->addGameObject(text1);
}

void GameOverState::draw() {
	ofBackground(ofColor::black);
	ofDrawBitmapString(getName(), 10, 20);

	State::draw();
}

void GameOverState::handleInput() {

	if (ofGetKeyPressed('x')) {
		ofExit();
	}

	State::handleInput();
}

void GameOverState::next() {
	game->changeState(new PlayState(game));
}