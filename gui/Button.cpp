#include "Button.hpp"
#include "../ent/Entity.hpp"
#include "../graphics/Drawer.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace gui {

using namespace drawer;

Button::Button(SDL_Renderer* rend, std::string text) : Item(m_rend), m_text(text) {
	m_unpushed = loadTexture(m_rend, "resource/gui/default_button_unpushed.png");
	m_pushed = loadTexture(m_rend, "resource/gui/default_button_pushed.png");
}

Button::~Button() {
	SDL_DestroyTexture(m_unpushed);
	SDL_DestroyTexture(m_pushed);
}

void Button::update() { }

void Button::render() const {
	drawTexture(m_rend, (m_pressed) ? m_unpushed : m_pushed, m_x, m_y, m_w, m_h);
}

}
}
