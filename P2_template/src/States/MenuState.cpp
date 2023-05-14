#include "PlayState.h"
#include "MenuState.h"
#include "../Utils/checkML.h"
    
void MenuState::draw() {
    ofBackground(0);
    ofDrawBitmapString(getName(), 10, 20);

    State::draw();
};

void MenuState::next(){
    game->changeState(new PlayState(game));
};
