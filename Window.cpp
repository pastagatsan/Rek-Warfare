#include "Window.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "graphics/Drawer.hpp"
#include "Log.hpp"
#include "ent/Entity.hpp"
#include "ent/Mob.hpp"
#include "ent/Player.hpp"

#include <iostream>
#include <string>

namespace rekwarfare {
namespace client {

Window::Window(std::string title, int x, int y, int width, int height)
	: m_title(title), m_x(x), m_y(y), m_width(width), m_height(height) {
	// Init our stuff
	m_win = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_width, m_height,
		SDL_WINDOW_SHOWN);
	if (!m_win) {
		std::string err = SDL_GetError();
		log(ERROR, "Window failed to create!: " + err);
	}

	// Assign m_x/y to proper values
	SDL_GetWindowPosition(m_win, &m_x, &m_y);

	m_renderer = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		std::string err = SDL_GetError();
		log(ERROR, "Renderer creation failed: " + err);
	}

	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
}

Window::~Window() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_win);
}


void Window::setup() {
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::string err = IMG_GetError();
		log(ERROR, "Could not init SDL_image! Reason: " + err);
	} else {
		log(STATUS, "SDL_Image initialized successfully!");
	}

	player = new Player(m_renderer, RAIDER, "Rodrun");
	player->setX(0);
	player->setY(0);
	player->setW(100);
	player->setH(100);
}

void Window::renderAll() {
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_QUIT:
				m_running = false;
				break;
		}
	}

	player->update();
	// Render everything from here:
	player->render();
}

void Window::clear() {
	SDL_RenderClear(m_renderer);
}

void Window::update() {
	SDL_RenderPresent(m_renderer);
}

}
}
