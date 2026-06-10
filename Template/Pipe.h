#pragma once
#include "../Core/Entity.h"

class renderSystem;
class Object;

class Pipe : public Entity {
public:
	//保留这两个子类是当前情况的无奈之举
	//因为修改渲染逻辑太麻烦了，我要过段时间再回头处理这个
	Object topPipe;
	Object bottomPipe;
	Pipe(
		float gapC,
		float gapH,
		Vector2 screenSize,
		Vector2 s,
		Vector2 p,
		Vector2 v,
		SDL_Texture* topTex,
		SDL_Texture* bottomTex
	);
	void update(float dt) override;
	void render();
	bool isOutOfScreen();
};