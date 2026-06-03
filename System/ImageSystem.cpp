#include "ImageSystem.h"
#include "RenderSystem.h"
#include <SDL_image.h>
#include <string>

ImageSystem::ImageSystem() {
    /*流程解释：
    和窗口初始化差不多的流程，先用IMG_Init来初始化什么类型的图片支持
    因为图片类型使用flag来表示，所以如果初始化成功，IMG_Init就会返回这个图片类型的flag的二进制
    通过and逻辑运算符判断该类型初始化是否成功，如果不成功，因为两个flag是不同的二进制，就会为假*/
    int result = IMG_Init(IMG_INIT_PNG);
    if (!(result & IMG_INIT_PNG))
    {
        SDL_Log("SDL_image init failed: %s", IMG_GetError());
    }
}

bool ImageSystem::LoadTexture(const std::string& id, const std::string& path, RenderSystem& render) {
    if (textureMap.find(id) != textureMap.end())
    {
        return true;
    }

    SDL_Surface* surface = IMG_Load(path.c_str());
    //surface是一块存在CPU的像素内存，直接储存每个像素的颜色数据
    //优点是其可以随时更改每一个像素的颜色，缺点是其需要把每一个像素的数据传递给GPU用于渲染

    if (!surface)
    {
        SDL_Log("IMG_Load failed: %s",
            IMG_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(render.getRenderer(), surface);
    //texture是GPU显存中的数据，GPU专门使用这种对象来进行绘制
    //优点是画的快，缺点则是其不能直接改像素的颜色
    if (!texture)
    {
        SDL_Log(
            "CreateTexture failed: %s",
            SDL_GetError()
        );
    }

    SDL_FreeSurface(surface);
    textureMap.emplace(id, texture);
    return true;
}

SDL_Texture* ImageSystem::GetTexture(const std::string& id) {
    auto it = textureMap.find(id);
    if (it != textureMap.end())
    {
        return it->second;
    }
    return nullptr;
}

void ImageSystem::UnloadTexture(const std::string& id)
{
    auto it = textureMap.find(id);

    if (it != textureMap.end())
    {
        SDL_DestroyTexture(it->second);
        textureMap.erase(it);
    }
}

void ImageSystem::Clear() {
    for (auto& pair : textureMap)
    {
        SDL_DestroyTexture(pair.second);
    }

    textureMap.clear();
    IMG_Quit();
}

