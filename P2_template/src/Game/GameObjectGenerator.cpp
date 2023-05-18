#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Blockage.h"
#include "Barrier.h"
#include "Pedestrian.h"
#include "Plane.h"
#include "../Utils/checkML.h"

GameObjectGenerator::GameObjectGenerator(Game* game) : game(game) { }

void GameObjectGenerator::generateWorld() {
    // CARRETERAS
    auto road_left = new Road(game, glm::vec3(0, OFFSET_Y, 0), glm::vec3(WIDTH_ROAD, 0, LENGTH_ROAD));
    game->addGameObject(road_left);

    auto road_right = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WIDTH_ROAD, 0, LENGTH_ROAD));
    game->addGameObject(road_right);

    auto road_top = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), glm::vec3(LENGTH_ROAD - 2 * WIDTH_ROAD, 0, WIDTH_ROAD));
    game->addGameObject(road_top);

    auto road_back = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), glm::vec3(LENGTH_ROAD - 2 * WIDTH_ROAD, 0, WIDTH_ROAD));
    game->addGameObject(road_back);

    auto road_center = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WIDTH_ROAD, 0, LENGTH_ROAD - 2 * WIDTH_ROAD), false);
    game->addGameObject(road_center);


    // MUROS EXTERIORES
    auto wall_LEFT = new Wall(game, glm::vec3(WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD));
    game->addGameObject(wall_LEFT);

    auto wall_BACK = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, -LENGTH_ROAD / 2), glm::vec3(LENGTH_ROAD + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_BACK);

    auto wall_RIGHT = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD));
    game->addGameObject(wall_RIGHT);

    auto wall_TOP = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, LENGTH_ROAD / 2), glm::vec3(LENGTH_ROAD + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_TOP);

    // MUROS INTERIORES
    auto wall_left = new Wall(game, glm::vec3(-WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(wall_left);
    auto wall_right = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(wall_right);
    // paredes verticales del centro
    auto wall_1 = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(wall_1);
    auto wall_2 = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(wall_2);

    int centerHoleWidth = (LENGTH_ROAD - 2 * WIDTH_ROAD - WIDTH_ROAD) / 2;

    auto wall_top_left = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2 + centerHoleWidth / 2, OFFSET_Y, LENGTH_ROAD / 2 - WIDTH_ROAD), glm::vec3(centerHoleWidth + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_top_left);
    auto wall_top_right = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2 - centerHoleWidth / 2, OFFSET_Y, LENGTH_ROAD / 2 - WIDTH_ROAD), glm::vec3(centerHoleWidth + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_top_right);
    auto wall_back_left = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2 + centerHoleWidth / 2, OFFSET_Y, -LENGTH_ROAD / 2 + WIDTH_ROAD), glm::vec3(centerHoleWidth + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_back_left);
    auto wall_back_right = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2 - centerHoleWidth / 2, OFFSET_Y, -LENGTH_ROAD / 2 + WIDTH_ROAD), glm::vec3(centerHoleWidth + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_back_right);

    // META
    // lo importante es el ancho
    auto goal = new Goal(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WIDTH_ROAD, WALL_SIZE, WALL_SIZE));
    goal->enableFixed(true);
    game->addGameObject(goal);

    // MONEDAS
    auto coin1 = new Coin(game, glm::vec3(0, 0, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), glm::vec3(50), 2);
    game->addGameObject(coin1);
    auto coin2 = new Coin(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, 0, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), glm::vec3(50), 2);
    game->addGameObject(coin2);
    auto coin3 = new Coin(game, glm::vec3(0, 0, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), glm::vec3(50), 2);
    game->addGameObject(coin3);
    auto coin4 = new Coin(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, 0, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), glm::vec3(50), 2);
    game->addGameObject(coin4);

    // OBSTACULO
    auto blockage = new Blockage(game, glm::vec3(0, 0, 400), glm::vec3(500, 200, 20)); // (ancho, altura, profundidad)
    game->addGameObject(blockage);

    // BARRERA
    auto barrier = new Barrier(game, glm::vec3(0, 100, -400), glm::vec3(400, 200, 50));
    game->addGameObject(barrier);

    // PEATON
    auto pedestrian = new Pedestrian(game, glm::vec3(WIDTH_ROAD / 2, 0, 1000), glm::vec3(50, 200, 50));
    game->addGameObject(pedestrian);

    // AVION
    // a lo ancho, hacia arriba, a lo largo
    auto plane = new Plane(game, glm::vec3(0, 300, 2000), glm::vec3(50));
    game->addGameObject(plane);
}