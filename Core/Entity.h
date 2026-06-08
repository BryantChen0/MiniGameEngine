#pragma once
#include "Object.h"
//实体逻辑父类继承实体对象的数据
//所有的实例的逻辑都会继承父类的逻辑
//进行数据和逻辑的分离的原因是
//有的实例不需要任何的更新逻辑，只需要知道它的数据就行，比如地面之类的场景
//那么这个情况下，我们在场景中只要初始化地面就行，别的都不需要去做
//而且不同的实例具有不同的更新逻辑，比如玩家需要输入，但是敌人不需要
//那么如果逻辑和数据放在一起，就会产生Object类变成一个上帝类，同时所有的实例对象变成必须更新了

class Entity : public Object {
public:
	Entity(Vector2 s, Vector2 p, Vector2 v);
	Entity();
	virtual void update(float dt) = 0;
};