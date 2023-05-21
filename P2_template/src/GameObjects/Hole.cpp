#include "Hole.h"
#include "Player.h"

void Hole::receiveCarCollision(Player* car) {
	car->fall();
}