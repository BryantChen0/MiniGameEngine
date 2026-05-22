cmake_minimum_required(VERSION 3.20)
project(MiniGameEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)

add_executable(MiniGameEngine
        main.cpp
        Math/Math.cpp
        "Math/Vector2.h"
        "Core/Object.cpp"
         "System/InputSystem.cpp" "System/InputSystem.h")

target_compile_definitions(MiniGameEngine PRIVATE SDL_MAIN_HANDLED)

target_link_libraries(MiniGameEngine PRIVATE
        SDL2::SDL2
        SDL2::SDL2main
        )
