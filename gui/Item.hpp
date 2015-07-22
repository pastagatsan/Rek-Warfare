#pragma once

#include "../ent/Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace gui {

	class Item : public Entity {

	public:
		Item(SDL_Renderer* rend);
		~Item();
		void setRX(int rx) { m_rbox.x = rx; }
		void setRY(int ry) { m_rbox.y = ry; }
		int getRX() const { return m_rbox.x; }
		int getRY() const { return m_rbox.y; }
	protected:
		SDL_Rect m_rbox;
	};
}
}
