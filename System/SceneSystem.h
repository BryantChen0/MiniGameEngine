#pragma once
#include <SDL2/SDL.h>
//场景管理类和场景接口类

class IScene {
	//使用virtual的原因：
	//如果不加 virtual：子类可以重写，但通过父类指针调用时会被忽略
	//如果加了 virtual：子类重写后，通过父类指针调用时会正确触发
	//换一种说法，因为gamescenemanager需要使用指针指向不同的gamescene类
	//而我们需要调用它们各自的更新和渲染方式
	//所以选择添加virtual保证其调用的是子类的方法而不是父类的方法
	//定义虚函数的原因是，如果子类没有定义，就在编译时报错，防止子类未定义而被调用
public:
	virtual void update(float dt) = 0;//虚函数
	virtual void render() = 0;
	virtual ~IScene() = default;
};

class SceneManager {
private:
	//使用指针，因为编译后需要切换不同的场景，而不是固定下来
	//同时指针可以指向任何继承IScene的类
	IScene* currentScene;

public:
	void switchScene(IScene* newScene);
	void update(float dt);
	void render();
};