#include "Game.h"
#include "Player.h"
#include "../Utils/checkML.h"

Game::Game() : bPlayerFinish(false), initTime(), player(nullptr), bDebug(false),
gameObjectsStates(), generator(nullptr), elapsedTime(0) {
    /*
    // TODO create settings
    ROAD_WIDTH = 2000;
    ROAD_LENGTH = 10000;
    */

    // generator = new GameObjectGenerator(this);

    for (auto& gameObjects : gameObjectsStates) {
        gameObjects = nullptr;//new GameObjectContainer();
    }
}

Game::~Game() {
    ofLogNotice() << "Deleting game";
    for (auto gameObjects : gameObjectsStates) {
        if (gameObjects != nullptr) {
            delete gameObjects;
        }
    }
    // delete gameObjects;
    if (generator != nullptr) {
        delete generator;
    }
    //delete currentState();
}

void Game::initGame() {
    // si había un generador de nivel, se elimina
    if (generator != nullptr) {
        delete generator;
        generator = nullptr;
    }

    generator = new GameObjectGenerator(this);

    /*
    if (gameObjects != nullptr) {
        delete gameObjects;
    }
    */

    // se crea el contenedor de gameObjects
    // gameObjects = new GameObjectContainer();

    // se crea el player
    player = new Player(this);
    //player->init();
    addGameObject(player);
    //gameObjects->add(player);

    // se setea la posición de la cámara
    cam.setPosition(0, 300, -600);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    cam.disableMouseInput();
    cam.setFarClip(100000);

    // se crea el mundo
    generator->generateWorld();
    //bPlayerFinish = false;

    // se inicia el contador
    initTime = ofGetElapsedTimef();
}

void Game::updateGameObjects() {
    // contador de tiempo, solo funciona durante el estado Play
    if (currentState()->getId() == ecs::_s_PLAY) {
        elapsedTime += ofGetLastFrameTime();
    }

    currentGameObjects()->update();
    //gameObjects->update();
}

void Game::drawGameObjects() {
    ofEnableLighting();
    ofEnableDepthTest();

    cam.begin();
    {
        if (bDebug) {
            currentGameObjects()->drawDebug();
            //gameObjects->drawDebug();
        }
        else {
            currentGameObjects()->draw();
            //gameObjects->draw();
        }
    }
    cam.end();

    ofDisableLighting();
    ofDisableDepthTest();
}


Player* Game::getPlayer() {
    return player;
}

vector<GameObject*> Game::getCollisions(GameObject* gameObject) {
    return currentGameObjects()->getCollisions(gameObject);
    //return gameObjects->getCollisions(gameObject);
}

void Game::addGameObject(GameObject* gameobject) {
    currentGameObjects()->add(gameobject);
    //gameObjects->add(gameobject);
}

void Game::reset(ecs::stateId id) {
    if (gameObjectsStates[id] != nullptr) {
        // se elimina el que había en el caso de que no sea la primera vez que se ha creado
        delete gameObjectsStates[id];
        gameObjectsStates[id] = nullptr;
    }
    // se crea uno nuevo
    gameObjectsStates[id] = new GameObjectContainer();
}

void Game::finishGame() {
    bPlayerFinish = true;
}

bool Game::isFinished() {
    return bPlayerFinish;
}

void Game::setFinished(bool v) {
    bPlayerFinish = v;
}

void Game::toggleDebug() {
    bDebug = !bDebug;
}

float Game::getEllapsedTime() {
    // diferencia de 1 segundo entre el de arriba y el de abajo
    //cout << elapsedTime << "   " << (ofGetElapsedTimef() - initTime) << endl;
    return elapsedTime;
    //return ofGetElapsedTimef() - initTime;
}