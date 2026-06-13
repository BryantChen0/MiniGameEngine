#include "Window.h"
#include <SDL2/SDL.h>


Window::Window(
    const char* title,
    int width,
    int height
)
{
    SDL_Init(SDL_INIT_VIDEO);

    window =
        SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            0
        );
}

SDL_Window* Window::getSDLWindow() {
    return window;
}

Window::~Window()
{
    SDL_DestroyWindow(window);

    SDL_Quit();
}