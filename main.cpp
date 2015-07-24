#include <iostream>
#include <string>
#include <stdexcept>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Window.hpp"
#include "Log.hpp"

int run(int argc, char* argv[]) {
	int window_width = 824;
	int window_height = 500;

	if (argc > 1){
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "help") == 0) {
			std::cout << "HELP" << std::endl;
			std::cout << "Default window dimensions are " << window_width
				<< "x" << window_height << std::endl;
			std::cout << "-w\tSets the window width" << std::endl;
			std::cout << "-h\tSets the window height" << std::endl;
			return 0; // We don't want to run the game
		} else {
			for (int i = 0; i < argc; i++){
				try {
					if ((strcmp(argv[i], "-w") == 0) && (i + 1 != argc)) {
						window_width = std::stoi(argv[i + 1]);
					} else if ((strcmp(argv[i], "-h") == 0) && (i + 1 != argc)) {
						window_height = std::stoi(argv[i + 1]);
					}
				} catch (const std::invalid_argument& inva) {
					logger::log(logger::ERROR, "No conversion could be made (stoi)");
				} catch (const std::out_of_range& oor) {
					logger::log(logger::ERROR, "Integer size out of range (stoi)");
				}
			}
		}
	}

	if (window_width < 100 || window_height < 100) {
		logger::log(logger::ERROR, "Why would window size be less than 100x100!?");
		return 1;
	}

	logger::log(logger::INFO, "New window dimensions are " + std::to_string(window_width)
		+ "x" + std::to_string(window_height));

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::string err = SDL_GetError();
		logger::log(logger::ERROR, "Couldn't init SDL! Reason: " + err);
		return 1;
	}

	Window window("Rek Warfare", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		window_width, window_height);

	window.setup();

	bool running = true;
	while ((running = window.isRunning())) {
		window.clear();

		window.renderAll();

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
