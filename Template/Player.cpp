#include "Player.h"
#include "../Core/Entity.h"
#include "../System/InputSystem.h"
#include "../System/PhysicalSystem.h"

Player::Player(InputSystem& inputSystem, PhysicalSystem& physicalSystem, Vector2 s, Vector2 p, Vector2 v)
	: input(inputSystem),
	physical(physicalSystem),
    Entity(s, p, v)
{}

void Player::update(float dt) {
    if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) velocity.x = 100;
    if (input.isKeyHeld(SDL_SCANCODE_LEFT))  velocity.x = -100;
    if (input.isKeyHeld(SDL_SCANCODE_UP))  velocity.y = -100;

    physical.moveObj(*this, dt);
    physical.applyGravity(*this, dt);
}