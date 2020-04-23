#include "Background.h"

Background::Background() {
}

Background::Background(sf::RenderWindow* window, GameObject* focus) {
	setWindow(window);
	setFocus(focus);
}

Background::~Background() {}

void Background::setWindow(sf::RenderWindow* window) {
	win = window;
}

sf::RenderWindow* Background::getWindow() {
	return win;
}

void Background::setFocus(GameObject* focus) {
	foc = focus;
}

GameObject* Background::getFocus() {
	return foc;
}

void Background::update(float dt) {
	sf::View view = win->getView();
	sf::Vector2f target = foc->getPosition() + sf::Vector2f(foc->getSize().x / 2, foc->getSize().y / 2) - view.getCenter();
	
	if (view.getCenter().x + win->getSize().x/2 + target.x > getSize().x) {
		target.x = 0;
		view.move(getSize().x - (view.getCenter().x + win->getSize().x/2), 0);
	}
	else if ((view.getCenter().x - win->getSize().x/2) + target.x < 0) {
		target.x = 0;
		view.move(-1 * view.getCenter().x + win->getSize().x/2, 0);
	}
	if (view.getCenter().y + win->getSize().y/2 + target.y > getSize().y) {
		target.y = 0;
		view.move(0, getSize().y - (view.getCenter().y + win->getSize().y/2));
	}
	else if (view.getCenter().y - win->getSize().y/2 + target.y < 0) {
		target.y = 0;
		view.move(0, -1 * view.getCenter().y + win->getSize().y/2);
	}
	view.move(target);
	
	win->setView(view);
}