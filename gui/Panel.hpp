/* The container for Items */
#pragma once

#include "../ent/Entity.hpp"
#include "Item.hpp"
#include "SDL2/SDL.h"
#include <string>

namespace entity {
namespace gui {

	const auto MAX_ITEMS = 256;

	class Panel : public Entity {

	public:
		Panel(SDL_Renderer* rend, int x, int y, int w, int h);
		void update() override;
		void render() const override;
		void setBackgroundEnabled(bool flag) { m_backgroundEnabled = flag; }
		void setBackgroundColor(Uint8 c[3]);
		void setBackgroundImage(SDL_Texture* bg);
		// Coordinates should be in relation with the panel dimensions
		// rx <= panel.width && rx + item.width <= panel.width
		void add(Item* item, int rx, int ry, int w, int h);
		bool backgroundEnabled() const { return m_backgroundEnabled; }
		// Set "panel name" for logging purposes. Not required, though
		void setName(std::string name) { m_name = name; }
	private:
		Item* m_items[MAX_ITEMS];
		int i_itemCount = 0;
		Uint8 m_bg[3] = { 0, 0, 0 };
		bool m_backgroundImageEnabled = false;
		bool m_backgroundEnabled = true;
		SDL_Texture* m_backgroundImage = nullptr;
		std::string m_name = "Unnamed";

	};

}
}
