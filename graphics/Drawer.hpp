#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace drawer {

	SDL_Texture* loadTexture(SDL_Renderer* rend, std::string path);
    /**
     * Renders a texture.
     *
     * rend - SDL_Renderer
     * texture - the texture
     * fraction - part of the texture to be rendered
     * size - coordinates, width, and height
     */
	void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* fraction=nullptr,
		SDL_Rect* size=nullptr);
	void setColor(SDL_Texture* texture, Uint8 r=NULL, Uint8 g=NULL, Uint8 b=NULL);
	void setAlpha(SDL_Texture* texture, Uint8 alpha=1);
}
