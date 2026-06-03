#include <SDL_image.h>
#include <string>
#include <unordered_map>

class RenderSystem;

class ImageSystem {
private:
	//将id作为不同texture加载的标识，如果有相同的id则不需要再加载图片
	std::unordered_map<
		std::string,
		SDL_Texture*
	> textureMap;
public:
	ImageSystem();
	bool LoadTexture(const std::string& id,const std::string& path, RenderSystem& render);
	SDL_Texture* GetTexture(const std::string& id);
	void UnloadTexture(const std::string& id);
	void Clear();
};