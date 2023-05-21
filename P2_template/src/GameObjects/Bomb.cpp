#include "Bomb.h"
#include "Player.h"
#include "../Game/Game.h"

Bomb::Bomb(Game* game, glm::vec3 pos, float limitY) : GameObject(game, pos, glm::vec3(SIZE)), limitY(limitY) {
	material.setDiffuseColor(ofColor::rosyBrown);
}

void Bomb::receiveCarCollision(Player* car) {
	car->resetPos();
}

void Bomb::checkCollisions() {
	vector<GameObject*> collisions = game->getCollisions(this);
	for (auto c : collisions) {
		c->receiveBombCollision(this);
	}
}

void Bomb::update() {
	transform.move(transform.getYAxis() * -SPEED * ofGetLastFrameTime());
	if (transform.getPosition().y < limitY) {
		kill();
	}
}

void Bomb::kill() {
	ofSoundPlayer explosion = game->getSound(ecs::_sound_EXPLOSION);
	explosion.play();
	// punto desde el que comienza el sonido, en milisegundos
	explosion.setPositionMS(700);
	GameObject::kill();
}