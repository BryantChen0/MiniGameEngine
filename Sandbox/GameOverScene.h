#pragma once
#include "../System/SceneSystem.h"
#include "../System/InputSystem.h"
#include "../Core/Object.h"
#include "../UI/UIText.h"

class RenderSystem;
class UIText;
class GameState;

class GameOverScene : public IScene {
private:
    RenderSystem& renderer;
    InputSystem& input;
    UIText gameOverText;
    UIText scoreText;
    GameState& data;
    bool restart = false;
public:
    GameOverScene(InputSystem& inputSystem, RenderSystem& renderSystem, GameState& gameState);
    void update(float dt) override;
    void render() override;
    SceneStatus getStatus() const override;
    std::string nextScene() const override;
    std::string getID() const override;
    void reset();
    ~GameOverScene() override = default;
};