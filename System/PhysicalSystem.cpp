#include "PhysicalSystem.h"
#include "../Math/Vector2.h"

void PhysicalSystem::moveObj(Object& obj, float dt) {
	obj.position = obj.position + obj.velocity*dt;
}

void PhysicalSystem::applyGravity(Object& obj, float dt) {
	//按照坐标轴来说，向下是加
	obj.velocity.y += gravity * dt;
}

bool checkRectCollision(
	Vector2 posA,Vector2 sizeA,
	Vector2 posB,Vector2 sizeB)
{
	//简简单单，碰撞的基础逻辑
	//因为两个物体碰撞有八种情况，但是没碰撞只有四种情况：
	//物体a的最右坐标小于b的最左
	//物体a的最左坐标大于b的最右
	//物体a的最下坐标小于b的最上
	//物体a的最上坐标大于b的最下
	//所以只要满足以上条件，就未碰撞，反之则碰撞
	if (posA.x + sizeA.x < posB.x) return false;
	if (posA.x > posB.x + sizeB.x) return false;
	if (posA.y + sizeA.y < posB.y) return false;
	if (posA.y > posB.y + sizeB.y) return false;

	return true;
}

bool PhysicalSystem::checkCollision(const Object& a, const Object& b) {
	//基于碰撞逻辑来对物体碰撞体进行判定
	for (const auto& colA : a.colliders) {
		for (const auto& colB : b.colliders) {
			Vector2 posA = a.position + colA.offset;
			Vector2 posB = b.position + colB.offset;

			if (checkRectCollision(
				posA,colA.collidersize,
				posB,colB.collidersize))
			{
				return true;
			}
		}
	}
	return false;
}