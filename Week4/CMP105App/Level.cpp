#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	window->setMouseCursorVisible(false);
	input = in;

	// initialise game objects
	texturePlayer.loadFromFile("gfx/Mushroom.png");
	textureEnemy1.loadFromFile("gfx/Goomba.png");
	textureEnemy2.loadFromFile("gfx/Beach_Ball.png");
	textureCursor.loadFromFile("gfx/icon.png");
	textureBackground.loadFromFile("gfx/Level1_1.png");

	player->setInput(input);
	player->setTexture(&texturePlayer);
	player->setSize(sf::Vector2f(128, 128));
	player->setPosition(128, 128);

	enemy1->setWindow(window);
	enemy1->setTexture(&textureEnemy1);
	enemy1->setSize(sf::Vector2f(128, 128));
	enemy1->setPosition(500, 500);
	enemy1->setVelocity(100, 100);

	enemy2->setWindow(window);
	enemy2->setTexture(&textureEnemy2);
	enemy2->setSize(sf::Vector2f(128, 128));
	enemy2->setPosition(270, 270);
	enemy2->setVelocity(-120, -50);

	cursor->setInput(input);
	cursor->setWindow(window);
	cursor->setTexture(&textureCursor);
	cursor->setSize(sf::Vector2f(48, 48));

	background->setWindow(window);
	background->setFocus(player);
	background->setTexture(&textureBackground);
	background->setSize(sf::Vector2f(10038, 675));
}

Level::~Level()
{
	delete player;
	delete enemy1;
	delete enemy2;
	delete cursor;
}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	player->handleInput(dt);
	cursor->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player->update(dt);
	enemy1->update(dt);
	enemy2->update(dt);
	background->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(*background);
	window->draw(*player);
	window->draw(*enemy1);
	window->draw(*enemy2);
	window->draw(*cursor);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}