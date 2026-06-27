#pragma once
#include "../System/SceneSystem.h"
#include "../System/ObjectManager.h"
#include "Player.h"
#include "Pipe.h"
#include "../Core/Object.h"

class InputSystem;
class PhysicalSystem;
class RenderSystem;
class ImageSystem;
class GameState;

class GameScene : public IScene {
private:
    Player player;
    //因为大部分游戏都需要多个同类型的对象，类似于子弹，敌人之类的东西，所以接下来在引擎层面需要实现多个同类对象的管理器
    ObjectManager<Pipe> pipes;
    float screenWidth;
    float screenHeight;
    bool gameOver = false;
    float pipeSpawnTimer = 0.0f;
    float pipeSpawnInterval = 2.0f;
    InputSystem& input;
    PhysicalSystem& physical;
    RenderSystem& renderer;
    ImageSystem& image;
    GameState& data;
public:
    GameScene(InputSystem& inputSystem, PhysicalSystem& physicalSystem, RenderSystem& renderSystem, ImageSystem& imageSystem, GameState& gameState, Vector2 screenSize);
    void spawnPipe();
    void update(float dt) override;
    void render() override;
    void loadImage();
    int getScore();
    SceneStatus getStatus() const override;
    std::string nextScene() const override;
    std::string getID() const override;
    void reset();
    ~GameScene() override = default;
};