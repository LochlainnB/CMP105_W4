#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class Cursor : public GameObject
{
public:
	Cursor();
	Cursor(Input* inpt, sf::RenderWindow* window);
	~Cursor();

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

	void handleInput(float dt) override;
protected:
	sf::RenderWindow* win;
};

