#pragma once

#include "SDL2/SDL.h"

namespace entity {

	class Entity {

	public:
		Entity(SDL_Rect box);
		virtual ~Entity();
		virtual void render();
		void setX(int x) { m_box.x = x; }
		void setY(int y) { m_box.y = y; }
		int getX() { return m_box.x; }
		int getY() { return m_box.y; }

	protected:
		SDL_Rect m_box;
	};
}
