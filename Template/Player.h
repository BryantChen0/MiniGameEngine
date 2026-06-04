#pragma once
#include "../Core/Entity.h"

class PhysicalSystem;
class InputSystem;

class Player : public Entity {
private:
	PhysicalSystem& physical;
	InputSystem& input;

public:
	Player(InputSystem& inputSystem, PhysicalSystem& physicalSystem, Vector2 s, Vector2 p, Vector2 v);
	void update(float dt) override;
};