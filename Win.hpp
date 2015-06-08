#pragma once

#include "SDL2/SDL.h"

#include <string>

class Win {

public:
    Win(std::string title, int x, int y, int width, int height);
    ~Win();
    void setup();
    /**
    * Render everything and handle entities in the window.
    * This includes handling of key input and window events
    */
    void renderAll(SDL_Event* e);
    void clear();
    void update();
    /**
    * Toggle logging of window events & other game events
    */
    void toggleLog();
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
    int m_x, m_y, m_width, m_height;
    bool m_logging = false;
    bool m_running = true;
    SDL_Window* m_win = nullptr;
    SDL_Renderer* m_renderer = nullptr;
protected:


};
