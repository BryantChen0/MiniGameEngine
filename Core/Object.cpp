#include "Object.h"
#include <iostream>
#include <SDL2/SDL.h>

Object::Object() {
	size = { 0, 0 };
	position = { 0, 0 };
	velocity = { 0, 0 };
}