#include "GameOverScene.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../UI/UIText.h"
#include "../Core/Object.h"
#include "iostream"
#include <SDL_ttf.h>

GameOverScene::GameOverScene(RenderSystem& renderSystem)
    :renderer(renderSystem)
{};

void GameOverScene::update(float dt) {}

void GameOverScene::render() {
    UIText text(renderer, "Game Over", 100, 100, 300, 80);
    text.render();
}