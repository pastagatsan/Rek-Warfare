#include "Win.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include <string>

Win::Win(std::string title, int x, int y, int width, int height) {
	m_title = title;
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	// Init our stuff
	m_win = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_width, m_height,
		SDL_WINDOW_SHOWN);
	if (!m_win) {
		std::cerr << "[Error] Win::m_win creation failed: " << SDL_GetError() << std::endl;
	}

	m_renderer = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		std::cerr << "[Error] Win::m_renderer creation failed: " << SDL_GetError() << std::endl;
	}
}

Win::~Win() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_win);
}

void Win::setup() {
	if (!((IMG_Init(IMG_INIT_PNG) < 0) & IMG_INIT_PNG)) {
		std::cerr << "Could not init SDL_image! Reason: " << IMG_GetError() << std::endl;
	}
}

void Win::renderAll(SDL_Event* e) {
	while (SDL_PollEvent(e)) {
		switch (e->type) {
			case SDL_QUIT:
				m_running = false;
				break;
		}
	}
}

void Win::clear() {
	SDL_RenderClear(m_renderer);
}

void Win::update() {
	SDL_RenderPresent(m_renderer);
}

void Win::toggleLog() {
	m_logging = (!m_logging) ? false : true;
}
