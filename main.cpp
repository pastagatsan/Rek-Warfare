#include <iostream>

#include "SDL2/SDL.h"
#include "Win.hpp"

int main(int, char**) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Could not init SDL!" << std::endl
        << "[Error] SDL_Init failed: " << SDL_GetError();
        return 1;
    }

    Win window("Rek Warfare", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600);
    std::cout << "[Window] x : " << window.getX() << std::endl << "[Window] y : " << window.getY()
        << std::endl;
    std::cout << "[Window] width : " << window.getWidth() << std::endl;
    std::cout << "[Window] height : " <<  window.getHeight() << std::endl;

    window.setup();

    bool running = true;
    SDL_Event e;
    while ((running = window.isRunning())) {
        window.clear();

        window.renderAll(&e);

        window.update();
    }
    // release everything here
    window.destroy();
    SDL_Quit();
    return 0;
}