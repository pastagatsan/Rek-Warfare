#include "Panel.hpp"
#include "../ent/Entity.hpp"

namespace gui {
	Panel::Panel(SDL_Renderer* rend, int x, int y, int w, int h)
		: entity::Entity(rend, m_rect) {
		// m_box resizing
		// TODO: Make a function in Entity to set all sizes (setSize(x,y,w,h))
		setX(x);
		setY(y);
		setW(w);
		setH(h);
	}

	void Panel::update() {
		// TODO: Have event stuff here
	}

	void Panel::render() const { }
}
