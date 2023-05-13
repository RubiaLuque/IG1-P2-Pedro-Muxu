#include "ofApp.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Player.h"
#include "Utils/checkML.h"

//--------------------------------------------------------------
void ofApp::setup(){
    game = new Game();
    game->pushState(new PlayState(game));
    //game->setState(new PlayState(game));
    ofSetFrameRate(60);
}

// se delega en cada uno de los estados
//--------------------------------------------------------------
void ofApp::update(){
    game->update();
    //game->currentState()->update();
    
    // un estado sabe si ha terminado, de modo que se pasa al siguiente
    if(game->isFinished()){
        game->next();
        //game->currentState()->next();
        game->setFinished(false);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    game->draw();
    //game->currentState()->draw();
}


void ofApp::keyPressed(int key){
    // pasar al siguiente estado
    // se hace por motivos de depuración
    if (key == ']') {
        game->next();
        //game->currentState()->next();
    }
    
    game->keyPressed(key);
    //game->currentState()->keyPressed(key);
}


void ofApp::keyReleased(int key){
    game->keyReleased(key);
    //game->currentState()->keyReleased(key);
}
