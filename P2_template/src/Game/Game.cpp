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


void Game::loadResources() {
    // TEXTURAS
    // se dejan de usar texturas rectangulares y se utilizan texturas 2D,
    // que son las que se utilizan en los dispositivos modernos
    ofDisableArbTex();
    // un mipmap es una imagen que contine la textura en diferentes resoluciones
    // cuando se mira desde cerca, se utiliza la de mayor resolución
    // y cuando se mira desde lejos, se usa de la menor resolución
    groundTexture.enableMipmap();
    ofLoadImage(groundTexture, GROUND_TEXTURE_PATH);

    oilSpillTexture.enableMipmap();
    ofLoadImage(oilSpillTexture, OIL_TEXTURE_PATH);

    warningTexture.enableMipmap();
    ofLoadImage(warningTexture, WARNING_TEXTURE_PATH);

    // FUENTES
    font.load(FONT_PATH, FONT_SIZE);
    assert(font.isLoaded());

    // SONIDOS
    sounds[ecs::_sound_EXPLOSION].load(EXPLOSION_SOUND_PATH);
    // se puede reproducir un sonido varias veces a la vez
    sounds[ecs::_sound_EXPLOSION].setMultiPlay(true);
    assert(sounds[ecs::_sound_EXPLOSION].isLoaded());

    sounds[ecs::_sound_SCREAM].load(SCREAM_SOUND_PATH);
    assert(sounds[ecs::_sound_SCREAM].isLoaded());

    sounds[ecs::_sound_COIN].load(COIN_SOUND_PATH);
    assert(sounds[ecs::_sound_COIN].isLoaded());

    sounds[ecs::_sound_COIN_DROP].load(COIN_DROP_SOUND_PATH);
    assert(sounds[ecs::_sound_COIN_DROP].isLoaded());

    sounds[ecs::_sound_GAMEOVER].load(GAMEOVER_SOUND_PATH);
    assert(sounds[ecs::_sound_GAMEOVER].isLoaded());

    sounds[ecs::_sound_SKID].load(SKID_SOUND_PATH);
    sounds[ecs::_sound_SKID].setMultiPlay(true);
    assert(sounds[ecs::_sound_SKID].isLoaded());

    sounds[ecs::_sound_WINNER].load(WINNER_SOUND_PATH);
    assert(sounds[ecs::_sound_WINNER].isLoaded());

    sounds[ecs::_sound_SUPER_MARIO_COIN].load(SUPER_MARIO_COIN_SOUND_PATH);
    assert(sounds[ecs::_sound_SUPER_MARIO_COIN].isLoaded());

    sounds[ecs::_sound_CLICK].load(CLICK_SOUND_PATH);
    assert(sounds[ecs::_sound_CLICK].isLoaded());
}


Game::Game() : bPlayerFinish(false), player(nullptr), bDebug(false),
gameObjectsStates(), generator(nullptr), elapsedTime(0), timesPath("times.json"), gameHasStarted(false), bGameOver(false) {

    for (auto& gameObjects : gameObjectsStates) {
        gameObjects = nullptr;
    }

    loadResources();
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
    // si había un generador de nivel, se elimina
    if (generator != nullptr) {
        delete generator;
        generator = nullptr;
    }

    generator = new GameObjectGenerator(this);

    // se crea el player
    player = new Player(this, glm::vec3(0, 0, 0));
    addGameObject(player);

    // se setea la posición de la cámara
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
    if (currentState()->getId() == ecs::_s_PLAY && gameHasStarted) {
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
        // se elimina el que había en el caso de que no sea la primera vez que se ha creado
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

void Game::gameOver() {
    bGameOver = true;
}

bool Game::isGameOver() {
    return bGameOver;
}

void Game::setGameOver(bool v) {
    bGameOver = v;
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
        // serialización del archivo .json
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