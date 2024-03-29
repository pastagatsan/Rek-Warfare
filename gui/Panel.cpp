#include "Panel.hpp"
#include "../ent/Entity.hpp"
#include "Item.hpp"
#include "SDL2/SDL.h"
#include "../graphics/Drawer.hpp"
#include "../Log.hpp"
#include <string>

namespace rekwarfare {
namespace client {

	Panel::Panel(SDL_Renderer* rend, int x, int y, int w, int h)
		: Entity(rend, m_box) {
		// m_box resizing
		setSize(w, h);
		setCoordinates(x, y);
		// initialize m_items to nullptr (needed?)
		for (auto& item : m_items) {
			item = nullptr;
		}
	}

	void Panel::update() {
		for (int i = 0; i < i_itemCount; i++) {
			m_items[i]->update();
		}
	}

	void Panel::render() const {
		for (int i = 0; i < i_itemCount; i++) {
			m_items[i]->render();
		}
		if (m_backgroundEnabled) {
			if (m_backgroundImageEnabled) {
				enableColorMod(false);
				drawTexture(m_rend, m_backgroundImage, m_box.x, m_box.y, m_box.w, m_box.h);
			} else {
				// TODO: Use SDL_gfxPrimitives.h
			}
		}
	}

	void Panel::setBackgroundColor(Uint8 c[3]) {
		m_bg[0] = c[0];
		m_bg[1] = c[1];
		m_bg[2] = c[2];
	}

	void Panel::setBackgroundImage(SDL_Texture* bg) {
		if (bg == nullptr) {
			m_backgroundImage = nullptr;
			m_backgroundImageEnabled = false;
		} else {
			m_backgroundImageEnabled = true;
			m_backgroundImage = bg;
		}
	}

	void Panel::add(Item* item, int rx, int ry, int w, int h) {
		if (!(i_itemCount >= 256)){
			if ((rx + w > m_box.w) || (ry + h > m_box.h) ||
				(rx < m_box.x) || (ry < m_box.y)) {
				log(WARNING, "Item #" + std::to_string(i_itemCount)
					+ " is out of bounds! (Panel " + m_name + ")");
			} else {
				item->setRX(rx);
				item->setRY(ry);
				item->setCoordinates(m_box.x + rx, m_box.y + ry);
				item->setSize(w, h);
			}

			m_items[i_itemCount] = item;
			i_itemCount++;
		} else {
			log(ERROR, "Panel" + m_name + " full! (limit = "
				+ std::to_string(MAX_ITEMS) + ")");
			return;
		}
	}
}
}
