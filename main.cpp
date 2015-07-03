#include <iostream>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Window.hpp"

int run(int argc, char* argv[]) {
	int window_width = 800;
	int window_height = 600;

	if (argc > 1){
		if (strcmp(argv[1], "--help")) {
			std::cout << "HELP" << std::endl;
			std::cout << "-w\tSets the window width" << std::endl;
			std::cout << "-h\tSets the window height" << std::endl;
		}

	// TODO: Handle options '-w' and '-h'

	if (window_width < 1 || window_height < 1) {
		std::cout << "Oh boy. You can't have a window smaller than 1x1!" << std::endl;
		return 1;
	}

	std::cout << "New window dimensions are " << window_width << "x" << window_height << std::endl;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Could not init SDL!" << std::endl
		<< "[Error] SDL_Init failed: " << SDL_GetError();
		return 1;
	}

	Window window("Rek Warfare", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		window_width, window_height);

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

int main(int argc, char* argv[]) {
	int result = run(argc, argv);
	// release everything here
	IMG_Quit();
	SDL_Quit();
	return result;
}
