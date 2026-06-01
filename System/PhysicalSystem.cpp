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
	//因为两个物体碰撞有八种情况，但是没碰撞只有四种情况：
	//物体a的最右坐标小于b的最左
	//物体a的最左坐标大于b的最右
	//物体a的最下坐标小于b的最上
	//物体a的最上坐标大于b的最下
	//所以只要满足以上条件，就未碰撞，反之则碰撞
	if (a.position.x + a.size.x < b.position.x) return false;
	if (a.position.x > b.position.x + b.size.x) return false;
	if (a.position.y + a.size.y < b.position.y) return false;
	if (a.position.y > b.position.y + b.size.y) return false;
	return true;
}