#include "Button.hpp"
#include "../ent/Entity.hpp"
#include "../graphics/Drawer.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace gui {

using namespace drawer;

Button::Button(SDL_Renderer* rend, SDL_Event* nev, std::string text)
	: Item(m_rend), m_text(text) {
	m_ev = nev;
	m_unpushed = loadTexture(m_rend, "resource/gui/default_button_unpushed.png");
	m_pushed = loadTexture(m_rend, "resource/gui/default_button_pushed.png");
}

Button::~Button() {
	SDL_DestroyTexture(m_unpushed);
	SDL_DestroyTexture(m_pushed);
}

void Button::update() {
	// Check if mouse is hovering
	if (m_ev->type == SDL_MOUSEMOTION) {
		int mox, moy;
		SDL_GetMouseState(&mox, &moy);
		if (mox >= m_box.x && mox <= m_box.x + m_box.w &&
			moy >= m_box.y && moy <= m_box.y + m_box.h) {
			m_hovered = true;
		} else {
			m_hovered = false;
		}
	}
	// Check press
	if (m_ev->type == SDL_MOUSEBUTTONDOWN && m_hovered) {
		m_pressed = (m_pressed) ? false : true;
	}
}

void Button::render() const {
	drawTexture(m_rend, (m_pressed) ? m_unpushed : m_pushed, m_box.x, m_box.y, m_box.w, m_box.h);
}

}
}
