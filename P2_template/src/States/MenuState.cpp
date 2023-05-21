#include "PlayState.h"
#include "MenuState.h"
#include "../Utils/checkML.h"
#include "../GameObjects/Button.h"

void MenuState::onEnter() {
    array<ofColor, 3> playColors = { ofColor::blue, ofColor::mediumBlue, ofColor::darkBlue };
    // una lambda expression puede tener referencia al contexto, es decir, tanto al this como a la variables locales
    // que hay donde se crea
    // Se indica en [] exactamente a que partes puede tener referencia
    Button* playButton = new Button(game, glm::vec2(ofGetWidth() / 2, ofGetHeight() / 3), 100, game->getFont(), "PLAY", ofColor::lightGray, playColors, glm::vec2(120, 70),
        [this]() {
            game->changeState(new PlayState(game));
        });
    playButton->setOrigin(glm::vec2(0.5, 0.5));
    game->addGameObject(playButton);

    array<ofColor, 3> quitColors = { ofColor::blue, ofColor::mediumBlue, ofColor::darkBlue };
    Button* quitButton = new Button(game, glm::vec2(ofGetWidth() / 2, 2 * ofGetHeight() / 3), 100, game->getFont(), "QUIT", ofColor::lightGray, quitColors, glm::vec2(155, 70),
        []() {
            ofExit();
        });
    quitButton->setOrigin(glm::vec2(0.5, 0.5));
    game->addGameObject(quitButton);
}
    
void MenuState::draw() {
    ofBackground(0);
    ofDrawBitmapString(getName(), 10, 20);

    State::draw();
};

void MenuState::next(){
    game->changeState(new PlayState(game));
};
