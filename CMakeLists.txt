cmake_minimum_required(VERSION 3.20)
project(MiniGameEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

add_executable(MiniGameEngine
        Sandbox/main.cpp
        Sandbox/GameScene.cpp
        Sandbox/GameOverScene.cpp
        Sandbox/Player.cpp
        Sandbox/Pipe.cpp
        Math/Math.cpp
        Math/Vector2.h
        Core/Object.cpp
        Core/Entity.cpp
        Core/Collider.h
        Core/Window.cpp
        System/InputSystem.cpp
        System/RenderSystem.cpp
        System/PhysicalSystem.cpp
        System/SceneSystem.cpp
        System/ImageSystem.cpp
        System/ObjectManager.h
        )

target_compile_definitions(MiniGameEngine PRIVATE SDL_MAIN_HANDLED)

target_link_libraries(MiniGameEngine PRIVATE
        SDL2::SDL2
        SDL2::SDL2main
        SDL2_image::SDL2_image
        SDL2_ttf::SDL2_ttf
)