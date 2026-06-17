#include "GameOverScene.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../UI/UIText.h"
#include "../Core/Object.h"

GameOverScene::GameOverScene(RenderSystem& renderSystem)
    :renderer(renderSystem),
    gameOverText(renderer, "Game Over", 100, 100, 300, 80),
    scoreText(renderer, "Score: 0", 100, 200, 300, 80)
{};

void GameOverScene::update(float dt) {}

void GameOverScene::render() {
    gameOverText.render();
    scoreText.render();
}

void GameOverScene::setScore(int newScore) {
    score = newScore;

    scoreText.setText(
        "Score: " + std::to_string(score)
    );
}