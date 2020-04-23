#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Cursor.h"
#include "Background.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Level objects
	sf::Texture texturePlayer;
	sf::Texture textureEnemy1;
	sf::Texture textureEnemy2;
	sf::Texture textureCursor;
	sf::Texture textureBackground;
	Player* player = new Player;
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Cursor* cursor = new Cursor;
	Background* background = new Background;
};