#include "Object.h"
#include <iostream>
#include <SDL2/SDL.h>

Object::Object(Vector2 s, Vector2 p, Vector2 v) {
	rendersize = s;
	position = p;
	velocity = v;
}