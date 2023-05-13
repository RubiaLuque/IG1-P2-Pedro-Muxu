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
    ofEasyCam cam;
    // el juego solo tiene referencia al player
    Player* player;
    // cada estado tiene un contenedor de objetos
    // de modo que puede haber dos estados activos a la vez
    array<GameObjectContainer*, ecs::maxStateId> gameObjectsStates;
    //GameObjectContainer* gameObjects;
    // generador del mapa, se utiliza solo en el PlayState
    // en el resto de estados, se añaden los objetos desde el propio estado
    GameObjectGenerator* generator;
    // debugear, es decir, en vez de mostrar los objetos, mostrar sus cajas de colisiones
    bool bDebug;
    // saber cuando ha terminado el estado actual para pasar al siguiente
    bool bPlayerFinish;
    // momento en el que ha empezado
    // se utiliza para saber cuanto tiempo se lleva de partida
    float initTime;

    inline GameObjectContainer* currentGameObjects() {
        return gameObjectsStates[currentState()->getId()];
    }

public:
    // TODO create settings
    /*
    const int ROAD_WIDTH = 2000;
    const int ROAD_LENGTH = 10000;
    */

    Game();

    ~Game();

    // iniciar el juego propiamente, es decir, lo que se ejecutaría en el PlayState
    void initGame();

    // update de los GameObjects que haya en el estado
    void updateGameObjects();
    // draw de los GameObjects que haya en el estado
    void drawGameObjects();

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

};
#endif
