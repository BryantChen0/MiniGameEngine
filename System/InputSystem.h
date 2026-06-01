#pragma once
#include <SDL2/SDL.h>
//输入系统类，将所有关于SDL的键盘输入封装起来
//只暴露接口给其他程序调用

class InputSystem {
private:
	//获取一个指向键盘状态数组的指针，由于数组只有0和1，所以用Uint8这个二进制的类型指针来指向
	const Uint8* currentKeys = nullptr;//本帧
	const Uint8* prevKeys[SDL_NUM_SCANCODES] = {};//上一帧
	bool quit = false;

public:
	void update();

	bool isKeyHeld(SDL_Scancode key);
	bool isKeyPressed(SDL_Scancode key);
	bool isKeyReleased(SDL_Scancode key);

	bool quitRequested();
};