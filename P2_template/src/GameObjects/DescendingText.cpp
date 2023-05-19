#include "DescendingText.h"
#include "../Game/Game.h"
#include "Player.h"

DescendingText::DescendingText(Game* game, glm::vec2 pos, int maxSize, int decrease, int number, ofTrueTypeFont font, vector<ofColor>colors) :
	Text(game, pos, maxSize, to_string(number), font, colors[0]), maxNumber(number), actNumber(number), colors(colors), decrease(decrease), elapsedTime(0), origin() {
	game->getPlayer()->setInputActivated(false);
	game->setGameHasStarted(false);
}

void DescendingText::update() {
	elapsedTime += ofGetLastFrameTime();
	if (elapsedTime > TIMER) {
		--actNumber;
		elapsedTime = 0;
		if (actNumber <= 0) {
			game->getPlayer()->setInputActivated(true);
			game->setGameHasStarted(true);

			kill();
		}
		else {
			color = colors[maxNumber - actNumber];
			text = to_string(actNumber);
			size -= decrease;
			setOrigin(origin);
		}
	}
}

void DescendingText::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	Text::setOrigin(origin);
}