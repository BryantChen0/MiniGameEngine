#pragma once
#include "../System/SceneSystem.h"
#include "../System/InputSystem.h"
#include "../Core/Object.h"
#include "../UI/UIText.h"

class RenderSystem;
class UIText;

class GameOverScene : public IScene {
private:
    RenderSystem& renderer;
    InputSystem& input;
    UIText gameOverText;
    UIText scoreText;
    bool restart = false;
    int score = 0;
public:
    GameOverScene(InputSystem& inputSystem, RenderSystem& renderSystem);
    void update(float dt) override;
    void render() override;
    void setScore(int newScore);
    SceneStatus getStatus() const override;
    SceneID nextScene() const override;
    void reset();
    ~GameOverScene() override = default;
};