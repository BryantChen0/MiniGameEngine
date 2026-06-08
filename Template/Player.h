#pragma once
#include "../Core/Entity.h"

class PhysicalSystem;
class InputSystem;

class Player : public Entity {
private:
	InputSystem& input;

public:
	Player(InputSystem& inputSystem, Vector2 s, Vector2 p, Vector2 v);
	void update(float dt) override;
	bool isOutOfScreen(float screenHeight);
};