//物理系统类，负责生成一系列物理逻辑函数
#pragma once
#include "../Core/object.h"

class PhysicalSystem {
private:
	float gravity = 98.0f;
	
public:
	void moveObj(Object& obj, float dt);//位置变化算是一种物理变化，所以将其放在这里
	void applyGravity(Object& obj, float dt);//添加重力导致的位置变化
	bool checkCollision(const Object& a, const Object& b);//判断是否碰撞
};