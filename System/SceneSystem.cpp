#include "SceneSystem.h"
#include <SDL2/SDL.h>
#include "InputSystem.h"
#include "PhysicalSystem.h"
#include "RenderSystem.h"

void SceneManager::registerScene(SceneID id, IScene* scene) {
	scenes.emplace(id, scene);
}

void SceneManager::switchScene(SceneID id) {
	currentScene = scenes[id];
}

void SceneManager::update(float dt) {
	if (currentScene) {
		currentScene->update(dt);
	}

	if (currentScene->getStatus()
		== SceneStatus::Finished)
	{
		currentScene =
			scenes[currentScene->nextScene()];
	}

}

void SceneManager::render() {
	if (currentScene) {
		currentScene->render();
	}
}

IScene* SceneManager::getCurrentScene()
{
	return currentScene;
}