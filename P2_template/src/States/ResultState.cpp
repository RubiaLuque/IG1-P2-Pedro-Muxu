#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"
#include "../Utils/checkML.h"
#include "../GameObjects/Text.h"

void ResultState::onEnter() {
    Text* title = new Text(game, glm::vec2(ofGetWidth() / 2, ofGetHeight() / 3), 100, "You Win!", game->getFont(), ofColor::green);
    title->setOrigin(glm::vec2(0.5, 0.5));
    game->addGameObject(title);

    Text* results = new Text(game, glm::vec2(ofGetWidth() / 2, 1.6 * ofGetHeight() / 3), 60, "Best results:", game->getFont(), ofColor::white);
    results->setOrigin(glm::vec2(0.5, 0.5));
    game->addGameObject(results);

    vector<float> times = game->loadTimes();
    for (int i = 0; i < times.size(); ++i) {
        string result = to_string(i + 1) + ".- " + to_string(times[i]) + " s";
        Text* timeResult = new Text(game, glm::vec2(ofGetWidth() / 2, 2 * ofGetHeight() / 3 + 60 * i), 45, result, game->getFont(), ofColor::white);
        timeResult->setOrigin(glm::vec2(0.5, 0.5));
        game->addGameObject(timeResult);
    }
}

void ResultState::draw() {
    ofBackground(127);
    ofDrawBitmapString(getName(), 10, 20);

    State::draw();
};

void ResultState::next() {
    game->changeState(new MenuState(game));
};