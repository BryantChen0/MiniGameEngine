#include "SceneSystem.h"
#include <SDL2/SDL.h>
#include "InputSystem.h"
#include "PhysicalSystem.h"
#include "RenderSystem.h"

void SceneManager::switchScene(IScene* newScene) {
	currentScene = newScene;
}

void SceneManager::update(float dt) {
	currentScene->update(dt);
}

void SceneManager::render() {
	currentScene->render();
}

IScene* SceneManager::getCurrentScene()
{
	return currentScene;
}