#include "SceneSystem.h"
#include <SDL2/SDL.h>
#include "InputSystem.h"
#include "PhysicalSystem.h"
#include "RenderSystem.h"

void SceneManager::switchScene(IScene* newScene) {
	currentScene = newScene;
}

void SceneManager::update(float dt,
	InputSystem& input,
	PhysicalSystem& physics) {
	currentScene->update(dt,input,physics);
}

void SceneManager::render(RenderSystem& render) {
	currentScene->render(render);
}
