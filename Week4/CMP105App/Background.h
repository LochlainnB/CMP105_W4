#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class Background : public GameObject {
public:
	Background();
	Background(sf::RenderWindow* window, GameObject* focus);
	~Background();

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
	void setFocus(GameObject* focus);
	GameObject* getFocus();

	void update(float dt) override;
protected:
	sf::RenderWindow* win;
	GameObject* foc;
};