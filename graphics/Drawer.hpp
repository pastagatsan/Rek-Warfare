#ifndef DRAWER_HPP
#define DRAWER_HPP

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
     * size - coordinates, width, and height 
     * fraction - part of the texture to be rendered
     */
    void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* size, SDL_Rect* fraction);
    void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* size);
}

#endif
