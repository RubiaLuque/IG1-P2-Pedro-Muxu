#include "PlayState.h"
#include "MenuState.h"
#include "../Utils/checkML.h"

void MenuState::update() {

};
    
void MenuState::draw() {
    ofBackground(0);
    ofDrawBitmapString(getName(), 10, 20);
};

void MenuState::next(){
    game->changeState(new PlayState(game));
    //game->setState(new PlayState(game));
};
