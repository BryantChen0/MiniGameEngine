#pragma once
#include "../Core/Entity.h"

class Object;

class Pipe : public Entity {
public:
	Object topPipe;
	Object bottomPipe;
	//需要改进的地方：
	//这里定义两个子Object是无奈之举，
	//因为物理系统的碰撞是两个Object的碰撞
	//改进的点是将物理系统的碰撞变成两个物体内部属性来作为参数
	Pipe(float gapC, float gapH, Vector2 screenSize, Vector2 s, Vector2 p, Vector2 v);
	void update(float dt) override;
	bool isOutOfScreen();
};