#include "Cursor.h"
Cursor::Cursor() {
}

Cursor::Cursor(Input* inpt, sf::RenderWindow* window) {
	setInput(inpt);
}

Cursor::~Cursor() {}

void Cursor::setWindow(sf::RenderWindow* window) {
	win = window;
}

sf::RenderWindow* Cursor::getWindow() {
	return win;
}

void Cursor::handleInput(float dt) {
	sf::View view = win->getView();
	sf::Vector2f originPos = view.getCenter() - sf::Vector2f(win->getSize().x / 2, win->getSize().y / 2);

	setPosition(input->getMouseX() + originPos.x, input->getMouseY() + originPos.y);
}