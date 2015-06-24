#include "Window.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "graphics/Drawer.hpp"

#include <iostream>
#include <string>

Window::Window(std::string title, int x, int y, int width, int height)
	: m_title(title), m_x(x), m_y(y), m_width(width), m_height(height) {
	// Init our stuff
	m_win = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_width, m_height,
		SDL_WINDOW_SHOWN);
	if (!m_win) {
		std::cerr << "[Error] Win::m_win creation failed: " << SDL_GetError() << std::endl;
	}

	// Assign m_x/y to proper values
	SDL_GetWindowPosition(m_win, &m_x, &m_y);

	m_renderer = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		std::cerr << "[Error] Win::m_renderer creation failed: " << SDL_GetError() << std::endl;
	}

	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
}

Window::~Window() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_win);
}

using namespace drawer;

void Window::setup() {
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Could not init SDL_image! Reason: " << IMG_GetError() << std::endl;
	} else {
		std::cout << "SDL_image initialized successfully!" << std::endl;
	}
	test = loadTexture(m_renderer, "resource/raider_emblem.png");
}

Uint8 rgb[3] = {0, 0, 0};

void Window::renderAll(SDL_Event* e) {
	while (SDL_PollEvent(e)) {
		switch (e->type) {
			case SDL_QUIT:
				m_running = false;
				break;
			case SDL_KEYDOWN:
				switch (e->key.keysym.sym) {
					case SDLK_r:
						rgb[0] += 16;
						break;
					case SDLK_f:
						rgb[0] -= 16;
						break;
					case SDLK_t:
						rgb[1] += 16;
						break;
					case SDLK_g:
						rgb[1] -= 16;
						break;
					case SDLK_y:
						rgb[2] += 16;
						break;
					case SDLK_h:
						rgb[2] -= 16;
						break;
					case SDLK_RETURN:
						rgb[2] = rgb[1] = rgb[0] = 0;
						break;
				}
				break;
		}
	}
	// Render everything from here:
	setColor(test, rgb[0], rgb[1], rgb[2]);
	drawTexture(m_renderer, test);
}

void Window::clear() {
	SDL_RenderClear(m_renderer);
}

void Window::update() {
	SDL_RenderPresent(m_renderer);
}

void Window::toggleLog() {
	m_logging = (!m_logging) ? false : true;
	std::cout << "[Event] Logging is now " << ((m_logging) ? "disabled" : "Enabled") << std::endl;
}
