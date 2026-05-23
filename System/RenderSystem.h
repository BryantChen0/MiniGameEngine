#pragma once
#include <SDL2/SDL.h>
#include "../Core/Object.h"
//渲染系统类，将所有渲染函数封装
//只暴露接口给别的程序调用

class RenderSystem {
private:
	SDL_Renderer* renderer = nullptr;

public:
	void init(SDL_Window* window);//初始化系统渲染器
	void clear(SDL_Color color);//每一帧清除画布，重新画背景
	void draw(Object obj, SDL_Color color);
	void present();//输出画布的结果
	void shutdown();//关闭渲染
	SDL_Renderer* getrenderer();//获取渲染器
};
