#include "RenderSystem.h"
#include "../Core/Object.h"

RenderSystem::RenderSystem(SDL_Window* window) {
    renderer = SDL_CreateRenderer(//创建渲染器
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
}

void RenderSystem::clear(SDL_Color color) {
    //窗口渲染
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);//改变渲染器颜色为对应颜色
    SDL_RenderClear(renderer);//使用渲染器作为橡皮擦，将整个缓存区擦成对应颜色
}

void RenderSystem::draw(Object obj, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {//长方形的渲染是从左上角的坐标开始以第三个参数为长度，第四个参数为宽度进行绘制
    (int)obj.position.x,
    (int)obj.position.y,
    (int)obj.size.x,
    (int)obj.size.y
    };
    SDL_RenderFillRect(renderer, &rect);
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