#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Window.hpp"

int run() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Could not init SDL!" << std::endl
		<< "[Error] SDL_Init failed: " << SDL_GetError();
		return 1;
	}

	Window window("Rek Warfare", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600);
	std::cout << "[Window] x : " << window.getX() << std::endl;
	std::cout << "[Window] y : " << window.getY() << std::endl;
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
	return 0;
}

int main(int, char**) {
	int result = run();
	// release everything here
	IMG_Quit();
	SDL_Quit();
	return result;
}
