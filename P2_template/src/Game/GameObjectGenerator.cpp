#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Blockage.h"
#include "Barrier.h"
#include "Pedestrian.h"
#include "../Utils/checkML.h"

GameObjectGenerator::GameObjectGenerator(Game* game) : game(game) { }

void GameObjectGenerator::generateWorld() {
    // carretera
    glm::vec3 roadPos(0, -50.1, L / 2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    game->addGameObject(road);

    // tamaño de las paredes
    int wallSize = 100;

    // muro formada por muchos bloques
    /*
    for (int l = 0; l < L; l += wallSize) {
        auto wall_r = new Wall(game,
            glm::vec3(-W / 2, roadPos.y, l - 1000 + wallSize / 2),
            glm::vec3(wallSize));
        game->addGameObject(wall_r);
    }
    */

    // muro derecho de un solo bloque
    auto wall_r = new Wall(game, glm::vec3(-W / 2, roadPos.y, roadPos.z), glm::vec3(100, 100, L));
    game->addGameObject(wall_r);

    // muro izquierdo de un solo bloque
    auto wall_l = new Wall(game, glm::vec3(W / 2, roadPos.y, roadPos.z), glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    // meta
    auto goal = new Goal(game, glm::vec3(0, roadPos.y, roadPos.z + L / 2), glm::vec3(W, 100, 100));
    game->addGameObject(goal);

    // moneda
    auto coin = new Coin(game, glm::vec3(0, 0, 2000), glm::vec3(50, 50, 50));
    game->addGameObject(coin);

    // obstaculo
    auto blockage = new Blockage(game, glm::vec3(0, roadPos.y + 100, 300), glm::vec3(500, 200, 20)); // (ancho, altura, profundidad)
    game->addGameObject(blockage);

    // barrera
    auto barrier = new Barrier(game, glm::vec3(500, roadPos.y + 100, 0), glm::vec3(400, 200, 50));
    game->addGameObject(barrier);

    // peaton
    auto pedestrian = new Pedestrian(game, glm::vec3(W / 2, roadPos.y, 1000), glm::vec3(50, 200, 50));
    game->addGameObject(pedestrian);

}