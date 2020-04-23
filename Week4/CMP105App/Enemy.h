#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class Enemy : public GameObject {
public:
	Enemy();
	Enemy(sf::RenderWindow* window);
	~Enemy();

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

	void update(float dt) override;
protected:
	sf::RenderWindow* win;
};