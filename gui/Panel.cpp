#include "Panel.hpp"
#include "../ent/Entity.hpp"
#include "Item.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace gui {
	Panel::Panel(SDL_Renderer* rend, int x, int y, int w, int h)
		: Entity(rend, m_box) {
		// m_box resizing
		// TODO: Make a function in Entity to set all sizes (setSize(x,y,w,h))
		setX(x);
		setY(y);
		setW(w);
		setH(h);
	}

	Panel::~Panel() { }

	void Panel::update() {
		// TODO: Have event stuff here
	}

	void Panel::render() const { }

	void Panel::setBackground(Uint8 c[3]) {
		m_bg[0] = c[0];
		m_bg[1] = c[1];
		m_bg[2] = c[2];
	}

	void Panel::add(Item*& item, int rx, int ry, int rw, int rh) {
		m_items[i_itemCount] = item;
		item->setRenderer(m_rend);
		i_itemCount++;
	}
}
}
