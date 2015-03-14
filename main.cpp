#include <iostream>
#include <error.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "graphics/Drawer.hpp"

void loop(bool running, SDL_Renderer* renderer, SDL_Rect* image_box, SDL_Texture* image);
void setup(SDL_Renderer*& renderer, SDL_Window* window, SDL_Texture* image);

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* image;
    SDL_Rect image_box = {200, 200, 100, 100};
    window = NULL;
    image = NULL;

    bool running = true;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Couldn't intizialize SDL! Error: " << SDL_GetError() << std::endl;
	return 1;
    } else {
        window = SDL_CreateWindow("Rek Warfare", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	
        if (window == NULL) {
            std::cerr << "Window not created!" << std::endl;
            return 1;
        } else {
	    setup(renderer, window, image);
            loop(running, renderer, &image_box, image);
        }
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

void loop(bool running, SDL_Renderer* renderer, SDL_Rect* image_box, SDL_Texture* image) {
    while (running) { 
	SDL_Event event;
        while (SDL_PollEvent(&event) !=  0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_RenderPresent(renderer);
        
        drawer::drawTexture(renderer, image, image_box);
        
        SDL_RenderClear(renderer);
    }
}

void setup(SDL_Renderer*& renderer, SDL_Window* window, SDL_Texture* image) {
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
      std::cerr << "Couldn't create renderer!" << std::endl;
    }
    
    if (IMG_Init(IMG_INIT_PNG) == 0) { 
	std::cerr << "Could not initialize IMG_INIT_PNG!" << std::endl;
    }
    
    std::string image_path = "resource/concept_classes.png";
    using namespace drawer;
    image = drawer::loadTexture(renderer, image_path.c_str());
    if (image == NULL) {
      std::cerr << "Couldn't create image.bmp!" << std::endl;
    }
}

