/* The container for Items */
#pragma once

#include "../ent/Entity.hpp"
#include "Item.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace gui {

	class Panel : public Entity {

	public:
		Panel(SDL_Renderer* rend, int x, int y, int w, int h);
		void update() override;
		void render() const override;
		void setBackground(Uint8 c[3]);
		// Coordinates should be in relation with the panel dimensions
		// rx <= panel.width && rx + item.width <= panel.width
		void add(Item*& item, int rx, int ry, int rw, int rh);
	private:
		Item* m_items[256];
		int i_itemCount = 0;
		Uint8 m_bg[3] = { 0, 0, 0 };

	};

}
}
