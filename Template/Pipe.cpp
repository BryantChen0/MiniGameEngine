#include"Pipe.h"
#include "../Core/Entity.h"
#include "../System/PhysicalSystem.h"
#include "../System/RenderSystem.h"

Pipe::Pipe(float gapC, float gapH, Vector2 screenSize, Vector2 s, Vector2 p, Vector2 v)
	: Entity(s, p, v),
	topPipe({ s.x, gapC - gapH / 2 }, 
		{ p.x, 0 },
		v),
	bottomPipe({ s.x, screenSize.y - (gapC + gapH / 2) },
		{ p.x, gapC + gapH / 2 },
		v)
{}

void Pipe::update(float dt) {
	velocity.x -= 10;
	topPipe.position.x = position.x;
	topPipe.velocity.x = velocity.x;
	bottomPipe.position.x = position.x;
	bottomPipe.velocity.x = velocity.x;
}

bool Pipe::isOutOfScreen()
{
	return position.x + size.x < 0;
}