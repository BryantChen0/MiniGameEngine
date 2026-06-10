#include "Pipe.h"
#include "../Core/Entity.h"
#include "../System/PhysicalSystem.h"
#include "../System/RenderSystem.h"

Pipe::Pipe(
    float gapC,
    float gapH,
    Vector2 screenSize,
    Vector2 s,
    Vector2 p,
    Vector2 v,
    SDL_Texture* topTex,
    SDL_Texture* bottomTex
)
    : Entity(s, p, v),
    topPipe({ s.x, gapC - gapH / 2 }, { p.x, 0 }, v),
    bottomPipe({ s.x, screenSize.y - (gapC + gapH / 2) }, { p.x, gapC + gapH / 2 }, v)
{
    topPipe.texture = topTex;
    bottomPipe.texture = bottomTex;

    colliders.push_back({
        {0, 0},
        {rendersize.x, gapC - gapH / 2}
        });

    colliders.push_back({
        {0, gapC + gapH / 2},
        {rendersize.x,
         screenSize.y - (gapC + gapH / 2)}
        });
}

void Pipe::update(float dt) {
	velocity.x -= 10;
	topPipe.position.x = position.x;
	bottomPipe.position.x = position.x;
}

bool Pipe::isOutOfScreen()
{
	if (position.x < -rendersize.x)
		destroy();

	return !isAlive();
}