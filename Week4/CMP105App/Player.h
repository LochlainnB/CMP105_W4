#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class Player : public GameObject
{
public:
	Player();
	Player(Input * inpt);
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
};

