#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"
#include "../Game/ecs_def.h"

class Player;

// Game funciona como un manager
// se utiliza cuando se quieren comunicar dos objetos
// Además, hereada de StateMachine
class Game : public StateMachine {
private:
    static const int MAX_TIMES = 3;
    const string FONT_PATH = "arial_narrow_7.ttf";
    const int FONT_SIZE = 100;
    const string EXPLOSION_PATH = "explosion.wav";
    const string SCREAM_PATH = "scream.mp3";
    const string GROUND_TEXTURE_PATH = "TexturesCom_Ground_ForestMoss02_header.jpg";
    const string OIL_TEXTURE_PATH = "oil_spill.jpg";
    const string WARNING_TEXTURE_PATH = "warning.jpg";

    ofEasyCam cam;
    // el juego solo tiene referencia al player
    Player* player;
    // cada estado tiene un contenedor de objetos
    // de modo que puede haber dos estados activos a la vez
    array<GameObjectContainer*, ecs::maxStateId> gameObjectsStates;
    // generador del mapa, se utiliza solo en el PlayState
    // en el resto de estados, se añaden los objetos desde el propio estado
    GameObjectGenerator* generator;
    // debugear, es decir, en vez de mostrar los objetos, mostrar sus cajas de colisiones
    bool bDebug;
    // saber cuando ha terminado el estado actual para pasar al siguiente
    bool bPlayerFinish;
    // contador con el tiempo que se está en el PlayState
    // se reinicia si ha terminado el juego y se vuelve a jugar
    float elapsedTime;
    string timesPath;
    bool gameHasStarted;
    bool bGameOver;

    // RECURSOS
    ofTrueTypeFont font;
    ofSoundPlayer explosionSound;
    ofSoundPlayer screamSound;
    ofTexture groundTexture;
    ofTexture oilSpillTexture;
    ofTexture warningTexture;

    inline GameObjectContainer* currentGameObjects() {
        return gameObjectsStates[currentState()->getId()];
    }

    void drawUIOrNot(bool isUIElement);

public:
    // Teclas que no están en el enum de openFrameworks
    static const int OF_KEY_SPACE = 32;

    Game();

    ~Game();

    // iniciar el juego propiamente, es decir, lo que se ejecutaría en el PlayState
    void initGame();

    // update de los GameObjects que hay en el estado
    void updateGameObjects();
    // draw de los GameObjects que hay en el estado
    void drawGameObjects();
    // handleInput de los GameObjects que hay en el estado
    void handleInputGameObjects();

    void gameOver();
    bool isGameOver();
    void setGameOver(bool v);

    void finishGame();
    bool isFinished();
    void setFinished(bool v);

    // intercambiar entre el modo normal o debug
    // de modo que en el debug solo se pintan las cajas de colisiones
    void toggleDebug();

    Player* getPlayer();

    // obtener todas las colisiones de un GameObject
    vector<GameObject*> getCollisions(GameObject* gameObject);

    // añadir un objeto a lista de objetos del estado
    void addGameObject(GameObject* gameobject);

    // resetear un estado, de modo que se elimina su contenedor de objetos
    // se utiliza cuando se vuelve a un estado de juego en el que ya se había estado
    void reset(ecs::stateId id);

    // tiempo en el programa desde que se entró en el juego, es decir,
    // en el estado PlayState
    float getEllapsedTime();

    void saveTime();

    vector<float> loadTimes();

    inline ofTrueTypeFont getFont() const {
        return font;
    }

    inline ofSoundPlayer getExplosionSound() const {
        return explosionSound;
    }

    inline ofSoundPlayer getScreamSound() const {
        return screamSound;
    }

    inline ofTexture getGroundTexture() const {
        return groundTexture;
    }

    inline ofTexture getOilSpillTexture() const {
        return oilSpillTexture;
    }

    inline ofTexture getWarningTexture() const {
        return warningTexture;
    }

    inline float getSizeRatio(float size) const {
        return size / FONT_SIZE;
    }

    template<typename T>
    inline T convertToProperSize(T value, float size) const {
        return value * size / FONT_SIZE;
    }

    inline void setGameHasStarted(bool hasStarted) {
        gameHasStarted = hasStarted;
    }
};
#endif
