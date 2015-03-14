#include "Drawer.hpp"

#include <iostream>
#include <error.h>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace drawer {

SDL_Texture* loadTexture(SDL_Renderer* rend, std::string path) {
    SDL_Texture* tex = NULL;
    SDL_Surface* load = IMG_Load(path.c_str());
    
    if (load == NULL) {
	std::cerr << "Could not load " << path << "!Reason: " << SDL_GetError() << std::endl;
    } else { 
	tex = SDL_CreateTextureFromSurface(rend, load);
	if (tex == NULL) { 
	    std::cerr << "Couldn't create texture from surface " << path << "!Reason: " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(load);
    }
    return tex;
}
    
void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* size, SDL_Rect* fraction) {
    SDL_RenderCopy(rend, texture, size, fraction);
}

void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* size) {
    drawer::drawTexture(rend, texture, size, NULL);
}
}