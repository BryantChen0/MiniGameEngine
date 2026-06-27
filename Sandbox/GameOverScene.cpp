#include "GameOverScene.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../UI/UIText.h"
#include "../Core/Object.h"
#include "GameState.h"
#include <SDL2/SDL.h>
#include <iostream>

GameOverScene::GameOverScene(InputSystem& inputSystem, RenderSystem& renderSystem, GameState& gameState)
    :renderer(renderSystem),
    input(inputSystem),
    gameOverText(renderer, "Game Over", 100, 100, 300, 80),
    scoreText(renderer, "Score: 0", 100, 200, 300, 80),
    data(gameState)
{};

void GameOverScene::update(float dt) {
    scoreText.setText(
        "Score: " + std::to_string(data.score)
    );
    if(input.isKeyPressed(SDL_SCANCODE_SPACE)) {
        std::cout << "Restart!" << std::endl;
        restart = true;
    }

}

void GameOverScene::render() {
    gameOverText.render();
    scoreText.render();
}

SceneStatus GameOverScene::getStatus() const {
    return restart
        ? SceneStatus::Finished
        : SceneStatus::Running;
}

std::string GameOverScene::nextScene() const{
    return "Game";
}

std::string GameOverScene::getID() const {
    return "GameOver";
}

void GameOverScene::reset() {
    data.score = 0;
    restart = false;
}