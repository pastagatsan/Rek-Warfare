#include <iostream>
#include <error.h>
#include "SDL.h"
//#include "SDL_image.h"

void loop(bool running, SDL_Renderer* renderer, SDL_Rect* image_box);
void setup(SDL_Renderer *&renderer, SDL_Window* window);

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    //SDL_Texture* image;
    SDL_Rect image_box = {200, 200, 100, 100};
    window = NULL;

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
        setup(renderer, window);
            loop(running, renderer, &image_box);
        }
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}

void loop(bool running, SDL_Renderer* renderer, SDL_Rect* image_box) {
    while (running) { 
	SDL_Event event;
        while (SDL_PollEvent(&event) !=  0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_RenderPresent(renderer);
        
        //SDL_RenderCopy(renderer, image, NULL, image_box);
	SDL_RenderDrawRect(renderer, image_box);
        
        SDL_RenderClear(renderer);
    }
}

void setup(SDL_Renderer*& renderer, SDL_Window* window) {
    renderer = NULL;
    //image = NULL;
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) { 
      std::cerr << "Couldn't create renderer!" << std::endl;
    } 
    
    /*std::string image_path = "image.bmp";
    image = IMG_LoadTexture(renderer, image_path.c_str());
    if (image == NULL) {
      std::cerr << "Couldn't create image.bmp!" << std::endl;
    }*/    
}
