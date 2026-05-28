#pragma once
#include <SDL2/SDL.h>
//渲染系统类，将所有渲染函数封装

class Object;

class RenderSystem {
private:
	SDL_Renderer* renderer = nullptr;

public:
	RenderSystem(SDL_Window* window);//初始化系统渲染器
	void clear(SDL_Color color);//每一帧清除画布，重新画背景
	void draw(Object obj, SDL_Color color);
	void present();//输出画布的结果
	void shutDown();//关闭渲染
	SDL_Renderer* getRenderer();//获取渲染器
};
