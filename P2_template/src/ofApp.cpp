#include "ofApp.h"
#include "MenuState.h"
#include "MenuState.h"
#include "Utils/checkML.h"

//--------------------------------------------------------------
void ofApp::setup() {
    game = new Game();
    game->pushState(new MenuState(game));
    ofSetFrameRate(60);
}

// se delega en cada uno de los estados
//--------------------------------------------------------------
void ofApp::update() {
    game->update();

    // un estado sabe si ha terminado, de modo que se pasa al siguiente
    if (game->isFinished()) {
        game->next();
        game->setFinished(false);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    game->draw();
}

void ofApp::keyPressed(int key) {
    // pasar al siguiente estado
    // se hace por motivos de depuración
    if (key == ']') {
        game->next();
    }

    game->handleInput();
    //game->keyPressed(key);
}

void ofApp::keyReleased(int key) {
    game->handleInput();
    //game->keyReleased(key);
}