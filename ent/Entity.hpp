#pragma once

#include "SDL2/SDL.h"

namespace entity {

	class Entity {

	public:
		Entity(SDL_Renderer* rend, SDL_Rect box);
		virtual ~Entity() { }
		virtual void update() { }
		virtual void render() const { }
		void setX(int x) { m_box.x = x; }
		void setY(int y) { m_box.y = y; }
		void setRenderer(SDL_Renderer*& rend) { m_rend = rend; }
		int getX() { return m_box.x; }
		int getY() { return m_box.y; }
		SDL_Renderer* getRenderer() { return m_rend; }

	protected:
		SDL_Rect m_box;
		SDL_Renderer* m_rend = nullptr;
	};
}
