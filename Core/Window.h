#pragma once
//游戏核心窗口生成类
struct SDL_Window;

class Window
{
public:
    Window(
        const char* title,
        int width,
        int height
    );

    ~Window();

    SDL_Window* getSDLWindow();

private:
    SDL_Window* window;
};