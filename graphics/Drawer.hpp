#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace drawer {

	SDL_Texture* loadTexture(SDL_Renderer* rend, std::string path);
	void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, int x, int y
		int w, int h, int xoff = -1, int yoff = -1, int tileW = -1, int tileH = -1);
	void setColor(SDL_Texture* texture, Uint8 r=0, Uint8 g=0, Uint8 b=0);
	void setAlpha(SDL_Texture* texture, Uint8 alpha=1);
}
