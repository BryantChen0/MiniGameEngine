#include "Player.h"
#include "../Core/Entity.h"
#include "../System/InputSystem.h"
#include "../System/PhysicalSystem.h"

Player::Player(InputSystem& inputSystem, Vector2 s, Vector2 p, Vector2 v)
	: input(inputSystem),
    Entity(s, p, v)
{
    colliders.push_back({
        {0, 0},
        s
        });
}

void Player::update(float dt) {
    if (input.isKeyHeld(SDL_SCANCODE_UP))  velocity.y = -200;
}

bool Player::isOutOfScreen(float screenHeight) {
    return position.y + rendersize.y > screenHeight;
}