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
// Adem�s, hereada de StateMachine
class Game : public StateMachine {
private:
    ofEasyCam cam;
    // el juego solo tiene referencia al player
    Player* player;
    // cada estado tiene un contenedor de objetos
    // de modo que puede haber dos estados activos a la vez
    array<GameObjectContainer*, ecs::maxStateId> gameObjectsStates;
    // generador del mapa, se utiliza solo en el PlayState
    // en el resto de estados, se a�aden los objetos desde el propio estado
    GameObjectGenerator* generator;
    // debugear, es decir, en vez de mostrar los objetos, mostrar sus cajas de colisiones
    bool bDebug;
    // saber cuando ha terminado el estado actual para pasar al siguiente
    bool bPlayerFinish;
    // contador con el tiempo que se est� en el PlayState
    // se reinicia si ha terminado el juego y se vuelve a jugar
    float elapsedTime;

    inline GameObjectContainer* currentGameObjects() {
        return gameObjectsStates[currentState()->getId()];
    }

public:
    // Teclas que no est�n en el enum de openFrameworks
    static const int OF_KEY_SPACE = 32;

    Game();

    ~Game();

    // iniciar el juego propiamente, es decir, lo que se ejecutar�a en el PlayState
    void initGame();

    // update de los GameObjects que hay en el estado
    void updateGameObjects();
    // draw de los GameObjects que hay en el estado
    void drawGameObjects();
    // handleInput de los GameObjects que hay en el estado
    void handleInputGameObjects();

    void finishGame();
    bool isFinished();
    void setFinished(bool v);

    // intercambiar entre el modo normal o debug
    // de modo que en el debug solo se pintan las cajas de colisiones
    void toggleDebug();

    Player* getPlayer();

    // obtener todas las colisiones de un GameObject
    vector<GameObject*> getCollisions(GameObject* gameObject);

    // a�adir un objeto a lista de objetos del estado
    void addGameObject(GameObject* gameobject);

    // resetear un estado, de modo que se elimina su contenedor de objetos
    // se utiliza cuando se vuelve a un estado de juego en el que ya se hab�a estado
    void reset(ecs::stateId id);

    // tiempo en el programa desde que se entr� en el juego, es decir,
    // en el estado PlayState
    float getEllapsedTime();

};
#endif
