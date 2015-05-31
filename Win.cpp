#include "Win.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include <iostream>
#include <string>

Win::Win(std::string title, int x, int y, int width, int height) {
    m_title = title;
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    // Init our stuff
    m_win = SDL_CreateWindow(Win::m_title.c_str(), m_x, m_y, m_width, m_height,
        SDL_WINDOW_SHOWN);
    if (!m_win) {
        std::cerr << "[Error] Win::m_win creation failed: " << SDL_GetError() << std::endl;
    }

    m_renderer = SDL_CreateRenderer(Win::m_win, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer) {
        std::cerr << "[Error] Win::m_renderer creation failed: " << SDL_GetError() << std::endl;
    }
}

void Win::setup() { }

void Win::renderAll(SDL_Event* e) {
    while (SDL_PollEvent(e)) {
        switch (e->type) {
            case SDL_QUIT:
                Win::m_running = false;
                break;
        }
    }
}

void Win::destroy() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_win);
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
