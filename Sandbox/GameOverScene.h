#pragma once
#include "../System/SceneSystem.h"
#include "../Core/Object.h"
#include "../UI/UIText.h"

class RenderSystem;
class UIText;

class GameOverScene : public IScene {
private:
    RenderSystem& renderer;
    UIText gameOverText;
    UIText scoreText;
public:
    int score = 0;
    GameOverScene(RenderSystem& renderSystem);
    void update(float dt) override;
    void render() override;
    void setScore(int newScore);
    ~GameOverScene() override = default;
};