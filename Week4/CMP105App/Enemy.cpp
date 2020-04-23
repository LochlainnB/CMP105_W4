#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(sf::RenderWindow* window) {
	setWindow(window);
}

Enemy::~Enemy() {}

void Enemy::setWindow(sf::RenderWindow* window) {
	win = window;
}

sf::RenderWindow* Enemy::getWindow() {
	return win;
}

void Enemy::update(float dt) {
	sf::View view = win->getView();
	sf::Vector2f originPos = view.getCenter() - sf::Vector2f(win->getSize().x / 2, win->getSize().y / 2);

	float targetX = getPosition().x + getVelocity().x * dt;
	float targetY = getPosition().y + getVelocity().y * dt;

	if (targetX < originPos.x) {
		targetX = abs(targetX - originPos.x) + originPos.x;
		setVelocity(getVelocity().x * -1, getVelocity().y);
	}
	else if (targetX > win->getSize().x + originPos.x - getSize().x) {
		targetX = 2 * (win->getSize().x - getSize().x + originPos.x) - targetX;
		setVelocity(getVelocity().x * -1, getVelocity().y);
	}
	if (targetY < originPos.y) {
		targetY = abs(targetY - originPos.y) + originPos.y;
		setVelocity(getVelocity().x, getVelocity().y * -1);
	}
	else if (targetY > win->getSize().y + originPos.y - getSize().y) {
		targetY = 2 * (win->getSize().y - getSize().y + originPos.y) - targetY;
		setVelocity(getVelocity().x, getVelocity().y * -1);
	}

	setPosition(targetX, targetY);
}