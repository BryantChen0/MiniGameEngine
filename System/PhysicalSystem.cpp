#include "PhysicalSystem.h"
#include "../Math/Vector2.h"

void PhysicalSystem::moveObj(Object& obj, float dt) {
	obj.position = obj.position + obj.velocity*dt;
}

void PhysicalSystem::applyGravity(Object& obj, float dt) {
	//按照坐标轴来说，向下是加
	obj.velocity.y += gravity * dt;
}

bool PhysicalSystem::checkCollision(const Object& a, const Object& b) {
	return false;
}