#include "RenderSystem.h"
#include "../Core/Object.h"
#include "../Core/Window.h"


RenderSystem::RenderSystem(Window& window) {
    renderer = SDL_CreateRenderer(//创建渲染器
        window.getSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
}

void RenderSystem::clear(SDL_Color color) {
    //窗口渲染
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);//改变渲染器颜色为对应颜色
    SDL_RenderClear(renderer);//使用渲染器作为橡皮擦，将整个缓存区擦成对应颜色
}

void RenderSystem::draw(Object& obj) {
    SDL_Rect dst = { (int)obj.position.x, (int)obj.position.y, (int)obj.rendersize.x, (int)obj.rendersize.y };
    //前两个参数是矩形左上角的坐标，后两个参数是矩形的长和宽，最后出来的结果是一个矩阵

    int r = SDL_RenderCopy(renderer, obj.texture, nullptr, &dst);

    if (r != 0)
    {
        SDL_Log("RenderCopy ERROR: %s", SDL_GetError());
    }
}

void RenderSystem::present() {
    SDL_RenderPresent(renderer);
}

void RenderSystem::shutDown() {
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer* RenderSystem::getRenderer() {
    return renderer;
}