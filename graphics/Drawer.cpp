#include "Drawer.hpp"

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace rekwarfare {
namespace client {

SDL_Texture* loadTexture(SDL_Renderer* rend, std::string path) {
	SDL_Texture* tex = nullptr;
	SDL_Surface* load = IMG_Load(path.c_str());

	if (load == nullptr) {
		std::cout << "Could not load " << path << "!Reason: " << SDL_GetError() << std::endl;
	} else {
		tex = SDL_CreateTextureFromSurface(rend, load);
		if (tex == nullptr) {
			std::cout << "Couldn't create texture from surface " << path << "!Reason: "
				<< SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(load);
	}
	return tex;
}

void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, int x, int y, int w, int h,
	int xoff, int yoff, int tileW, int tileH) {
	SDL_Rect fraction = { xoff, yoff, tileW, tileH };
	SDL_Rect size = { x, y, w, h };
	SDL_RenderCopy(rend, texture, (tileW < 0 && tileH < 0) ? NULL : &fraction, &size);
}

void setColor(SDL_Texture* texture, Uint8 r, Uint8 g, Uint8 b) {
	if (enable_color_mod)
		SDL_SetTextureColorMod(texture, r, g, b);
}

void setAlpha(SDL_Texture* texture, Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

void enableColorMod(bool flag) {
	enable_color_mod = flag;
}

}
}
