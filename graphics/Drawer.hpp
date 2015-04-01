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
    void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* fraction, SDL_Rect* size);
    void drawTexture(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect* size);
}
