#include "GameOverScene.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../UI/UIText.h"
#include "../Core/Object.h"
#include <SDL2/SDL.h>
#include <iostream>

GameOverScene::GameOverScene(InputSystem& inputSystem, RenderSystem& renderSystem)
    :renderer(renderSystem),
    input(inputSystem),
    gameOverText(renderer, "Game Over", 100, 100, 300, 80),
    scoreText(renderer, "Score: 0", 100, 200, 300, 80)
{};

void GameOverScene::update(float dt) {
    if(input.isKeyPressed(SDL_SCANCODE_SPACE)) {
        std::cout << "Restart!" << std::endl;
        restart = true;
    }

}

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

SceneStatus GameOverScene::getStatus() const {
    return restart
        ? SceneStatus::Finished
        : SceneStatus::Running;
}

SceneID GameOverScene::nextScene() const{
    return SceneID::Game;
}

void GameOverScene::reset() {
    restart = false;
}