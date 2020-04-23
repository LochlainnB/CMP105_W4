#include "Player.h"
Player::Player() {
}

Player::Player(Input * inpt) {
	setInput(inpt);
}

Player::~Player() {}

void Player::handleInput(float dt) {
	setVelocity(0, 0);
	if (input->isKeyDown(0)) { //a
		setVelocity(-200, 0);
	}
	else if (input->isKeyDown(3)) { //d
		setVelocity(200, 0);
	}
	if (input->isKeyDown(22)) { //w
		setVelocity(getVelocity().x, -200);
	}
	else if (input->isKeyDown(18)) { //s
		setVelocity(getVelocity().x, 200);
	}
}

void Player::update(float dt) {
	setPosition(getPosition() + getVelocity() * dt);
}