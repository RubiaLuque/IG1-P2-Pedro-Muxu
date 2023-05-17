#include "Game.h"
#include "Player.h"
#include "../Utils/checkML.h"

void Game::drawUIOrNot(bool isUIElement) {
    if (bDebug) {
        currentGameObjects()->drawDebug(isUIElement);
    }
    else {
        currentGameObjects()->draw(isUIElement);
    }
}

Game::Game() : bPlayerFinish(false), player(nullptr), bDebug(false),
gameObjectsStates(), generator(nullptr), elapsedTime(0), timesPath("times.json") {

    for (auto& gameObjects : gameObjectsStates) {
        gameObjects = nullptr;
    }

    font.load(FONT_PATH, FONT_SIZE);
    assert(font.isLoaded());
}

Game::~Game() {
    ofLogNotice() << "Deleting game";
    for (auto gameObjects : gameObjectsStates) {
        if (gameObjects != nullptr) {
            delete gameObjects;
        }
    }
    if (generator != nullptr) {
        delete generator;
    }
}

void Game::initGame() {
    // si hab�a un generador de nivel, se elimina
    if (generator != nullptr) {
        delete generator;
        generator = nullptr;
    }

    generator = new GameObjectGenerator(this);

    // se crea el player
    player = new Player(this);
    addGameObject(player);

    // se setea la posici�n de la c�mara
    cam.setPosition(0, 300, -600);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    cam.disableMouseInput();
    cam.setFarClip(100000);

    // se crea el mundo
    generator->generateWorld();

    // se inicia el contador
    // initTime = ofGetElapsedTimef();
}

void Game::updateGameObjects() {
    // contador de tiempo, solo funciona durante el estado Play
    if (currentState()->getId() == ecs::_s_PLAY) {
        elapsedTime += ofGetLastFrameTime();
    }

    currentGameObjects()->update();
}

void Game::drawGameObjects() {
    ofEnableLighting();
    ofEnableDepthTest();

    cam.begin();
    {
        drawUIOrNot(false);
    }
    cam.end();

    ofDisableLighting();
    ofDisableDepthTest();

    drawUIOrNot(true);
}

void Game::handleInputGameObjects() {
    currentGameObjects()->handleInput();
}

Player* Game::getPlayer() {
    return player;
}

vector<GameObject*> Game::getCollisions(GameObject* gameObject) {
    return currentGameObjects()->getCollisions(gameObject);
}

void Game::addGameObject(GameObject* gameobject) {
    currentGameObjects()->add(gameobject);
}

void Game::reset(ecs::stateId id) {
    if (gameObjectsStates[id] != nullptr) {
        // se elimina el que hab�a en el caso de que no sea la primera vez que se ha creado
        delete gameObjectsStates[id];
        gameObjectsStates[id] = nullptr;
    }
    // se crea uno nuevo
    gameObjectsStates[id] = new GameObjectContainer();
    // contador a cero si se ha vuelto a crear el PlayState
    if (id == ecs::_s_PLAY) {
        elapsedTime = 0;
    }
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
    return elapsedTime;
    // return ofGetElapsedTimef() - initTime;
}

void Game::saveTime() {

    vector<float> times;
    times.reserve(MAX_TIMES);

    // la ruta es relativa a la carpeta data
    ofFile file(ofToDataPath(timesPath));
    if (file.exists()) {
        ofJson json = ofLoadJson(file);
        // serializaci�n del archivo .json
        // muestra lo que hay escrito
        cout << json.dump() << endl;
        auto jsonValue = json["times"];
        if (jsonValue != nullptr && jsonValue.is_array()) {
            for (auto& v : jsonValue) {
                times.push_back(v);
            }
        }
    }
    else {
        // crea el archivo
        file.create();
    }

    times.push_back(elapsedTime);
    std::sort(times.begin(), times.end());
    if (times.size() > MAX_TIMES) {
        times.pop_back();
    }

    ofJson json = ofLoadJson(timesPath);
    json["times"] = times;

    ofSavePrettyJson(timesPath, json);
}

vector<float> Game::loadTimes() {
    // la ruta es relativa a la carpeta data
    ofFile file(ofToDataPath(timesPath));
    if (file.exists()) {
        ofJson json = ofLoadJson(file);
        auto jsonValue = json["times"];
        if (jsonValue != nullptr && jsonValue.is_array()) {
            return jsonValue;
        }
    }
}