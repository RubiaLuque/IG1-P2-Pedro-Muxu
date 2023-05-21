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
#include "Hole.h"
#include "Ground.h"
#include "CrazyBow.h"
#include "Well.h"
#include "OilSpill.h"
#include "DeadlyTile.h"
#include "Crane.h"
#include "../Utils/checkML.h"
#include "HoistLeg.h"

GameObjectGenerator::GameObjectGenerator(Game* game) : game(game) { }

void GameObjectGenerator::generateWorld() {
    // anchos de las carreteras a los lados del pozo
    int wRoadsNextWell = (WIDTH_ROAD - WIDTH_ROAD / 2) / 2;
    // alto de las carreteras arriba y abajo del pozo
    int hRoadsFrontBehindWell = (LENGTH_ROAD - WIDTH_ROAD / 2) / 2;
    // ancho de los huecos a los lados de la carretera central
    int widthCenterHole = (LENGTH_ROAD - 2 * WIDTH_ROAD - WIDTH_ROAD) / 2;

    // CARRETERAS
    auto road_left = new Road(game, glm::vec3(0, OFFSET_Y, 0), glm::vec3(WIDTH_ROAD, 0, LENGTH_ROAD));

    game->addGameObject(road_left);
    auto road_right_left = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD - wRoadsNextWell / 2, OFFSET_Y, 0), glm::vec3(wRoadsNextWell, 0, WIDTH_ROAD / 2), false);
    game->addGameObject(road_right_left);
    auto road_right_right = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + wRoadsNextWell / 2, OFFSET_Y, 0), glm::vec3(wRoadsNextWell, 0, WIDTH_ROAD / 2), false);
    game->addGameObject(road_right_right);
    auto road_right_top = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, OFFSET_Y, WIDTH_ROAD / 4 + hRoadsFrontBehindWell / 2), glm::vec3(WIDTH_ROAD, 0, hRoadsFrontBehindWell), false);
    game->addGameObject(road_right_top);
    auto road_right_down = new Road(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, OFFSET_Y, -WIDTH_ROAD / 4 - hRoadsFrontBehindWell / 2), glm::vec3(WIDTH_ROAD, 0, hRoadsFrontBehindWell), false);
    game->addGameObject(road_right_down);

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
    // izquierda
    auto wall_1 = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(wall_1);
    // derecha
    auto wall_2 = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(WALL_SIZE, WALL_SIZE, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(wall_2);

    auto wall_top_left = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2 + widthCenterHole / 2, OFFSET_Y, LENGTH_ROAD / 2 - WIDTH_ROAD), glm::vec3(widthCenterHole + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_top_left);
    auto wall_top_right = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2 - widthCenterHole / 2, OFFSET_Y, LENGTH_ROAD / 2 - WIDTH_ROAD), glm::vec3(widthCenterHole + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_top_right);
    auto wall_back_left = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2 + widthCenterHole / 2, OFFSET_Y, -LENGTH_ROAD / 2 + WIDTH_ROAD), glm::vec3(widthCenterHole + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_back_left);
    auto wall_back_right = new Wall(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2 - widthCenterHole / 2, OFFSET_Y, -LENGTH_ROAD / 2 + WIDTH_ROAD), glm::vec3(widthCenterHole + WALL_SIZE, WALL_SIZE, WALL_SIZE));
    game->addGameObject(wall_back_right);

    // META
    // lo importante es el ancho
    auto goal = new Goal(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y + HEIGHT_GOAL / 2, 0), glm::vec3(WIDTH_ROAD, HEIGHT_GOAL, WALL_SIZE), SIZE_GOAL_BARS);
    goal->enableFixed(true);
    game->addGameObject(goal);

    // MONEDAS
    auto coin1 = new Coin(game, glm::vec3(0, RADIUS_COIN / 3, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), HEIGHT_COIN, RADIUS_COIN, 2);
    game->addGameObject(coin1);
    auto coin2 = new Coin(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, RADIUS_COIN / 3, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), HEIGHT_COIN, RADIUS_COIN, 2);
    game->addGameObject(coin2);
    auto coin3 = new Coin(game, glm::vec3(0, RADIUS_COIN / 3, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), HEIGHT_COIN, RADIUS_COIN, 2);
    game->addGameObject(coin3);
    auto coin4 = new Coin(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, RADIUS_COIN / 3, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), HEIGHT_COIN, RADIUS_COIN, 2);
    game->addGameObject(coin4);

    // OBSTACULO
    auto blockage = new Blockage(game, glm::vec3(0, 0, 400), glm::vec3(500, 100, 20)); // (ancho, altura, profundidad)
    game->addGameObject(blockage);

    // BARRERA
    auto barrier = new Barrier(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, 0, -400), glm::vec3(400, 200, 50));
    game->addGameObject(barrier);

    // PEATON
    auto pedestrian = new Pedestrian(game, glm::vec3(WIDTH_ROAD / 2 - 2 * WALL_SIZE, OFFSET_Y, 1000), 250, glm::vec4(90, 0, 1, 0));
    game->addGameObject(pedestrian);

    // AVION
    // a lo ancho, hacia arriba, a lo largo
    auto plane = new Plane(game, glm::vec3(0, 150, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), glm::vec3(0, 150, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), 100, OFFSET_Y);
    game->addGameObject(plane);

    // HUECOS
    auto hole_left = new Hole(game, glm::vec3(3 * WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(2 * WIDTH_ROAD, WALL_SIZE / 5, LENGTH_ROAD + WIDTH_ROAD * 4));
    game->addGameObject(hole_left);
    auto hole_right = new Hole(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD - WIDTH_ROAD, OFFSET_Y, 0), glm::vec3(2 * WIDTH_ROAD, WALL_SIZE / 5, LENGTH_ROAD + WIDTH_ROAD * 4));
    game->addGameObject(hole_right);
    auto hole_top = new Hole(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, LENGTH_ROAD / 2 + WIDTH_ROAD), glm::vec3(LENGTH_ROAD, WALL_SIZE / 5, 2 * WIDTH_ROAD));
    game->addGameObject(hole_top);
    auto hole_back = new Hole(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, -LENGTH_ROAD / 2 - WIDTH_ROAD), glm::vec3(LENGTH_ROAD, WALL_SIZE / 5, 2 * WIDTH_ROAD));
    game->addGameObject(hole_back);
    auto hole_center_left = new Hole(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 + WIDTH_ROAD / 2 + widthCenterHole / 2, OFFSET_Y, 0), glm::vec3(widthCenterHole, WALL_SIZE / 5, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(hole_center_left);
    auto hole_center_right = new Hole(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2 - WIDTH_ROAD / 2 - widthCenterHole / 2, OFFSET_Y, 0), glm::vec3(widthCenterHole, WALL_SIZE / 5, LENGTH_ROAD - 2 * WIDTH_ROAD));
    game->addGameObject(hole_center_right);

    // TIERRA QUE REDUCE LA VELOCIDAD
    auto ground = new Ground(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y + 1, LENGTH_ROAD / 2 - WIDTH_ROAD / 2), glm::vec3(500, 10, 500), 80);
    game->addGameObject(ground);

    //POZO
    auto well = new Well(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, OFFSET_Y, 0), glm::vec3(600, 10, 600), 700, ofColor::crimson);
    game->addGameObject(well); //pared exterior del pozo
    auto well_2 = new Well(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD + WIDTH_ROAD / 2, OFFSET_Y + 1, 0), glm::vec3(500, 10, 500), 600, ofColor::black);
    game->addGameObject(well_2); //interior del pozo

    //ARCO LOCO
    auto crazyBow = new CrazyBow(game, glm::vec3(-WIDTH_ROAD, OFFSET_Y + HEIGHT_BOW / 2, LENGTH_ROAD / 2 - WIDTH_ROAD / 2),
        glm::vec3(WIDTH_ROAD, HEIGHT_BOW, WALL_SIZE), 18, 4, 30, glm::vec4(-90, 0, 1, 0), 10);
    crazyBow->enableFixed(true);
    game->addGameObject(crazyBow);

    //MANCHA DE ACEITE QUE CAMBIA TU DIRECCIÓN
    auto oilSpill = new OilSpill(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2),
        glm::vec3(500, 20, 500));
    game->addGameObject(oilSpill);

    //BALDOSA MORTIFERA (te hace perder el juego si la pisas)
    auto deadlyTile = new DeadlyTile(game, glm::vec3(WIDTH_ROAD / 2 - LENGTH_ROAD / 2, OFFSET_Y, -WIDTH_ROAD),
        glm::vec3(500, 20, 500));
    game->addGameObject(deadlyTile);

    // GRÚA
    auto hoist = new HoistLeg(game, glm::vec3(-WIDTH_ROAD / 2 - 200, OFFSET_Y + 250, -LENGTH_ROAD / 2 + WIDTH_ROAD / 2), glm::vec3(80, 500, 80));
    game->addGameObject(hoist);

}