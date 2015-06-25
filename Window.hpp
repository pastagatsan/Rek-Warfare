#pragma once

#include "SDL2/SDL.h"
#include "graphics/Drawer.hpp"

#include <string>

class Window {

public:
	Window(std::string title, int x, int y, int width, int height);
	~Window();
	void setup();
	/**
	* Render everything and handle entities in the window.
	* This includes handling of key input and window events
	*/
	void renderAll(SDL_Event* e);
	void clear();
	void update();

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getX() { return m_x; }
	int getY() { return m_y; }
	bool isRunning() { return m_running; }
	std::string getTitle() { return m_title; }
	SDL_Window* getWindow() { return m_win; }
	SDL_Renderer* getRenderer() { return m_renderer; }

private:
	std::string m_title;
	int m_x = 0, m_y = 0, m_width = 0, m_height = 0;
	bool m_running = true;
	SDL_Window* m_win = nullptr;
	SDL_Renderer* m_renderer = nullptr;
protected:
	SDL_Texture* test = nullptr;

};
