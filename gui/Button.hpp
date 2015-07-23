#pragma once

#include "../ent/Entity.hpp"
#include "Item.hpp"
#include "SDL2/SDL.h"

#include <string>

namespace entity {
namespace gui {

	class Button : public Item {

	public:
		Button(SDL_Renderer* rend, SDL_Event* nev, std::string text);
		~Button();
		virtual void update() override;
		virtual void render() const override;
	private:
		SDL_Texture* m_unpushed = nullptr, *m_pushed = nullptr;
	protected:
		SDL_Event* m_ev = nullptr;
		bool m_pressed = false;
		bool m_hovered = false;
		std::string m_text = "Button";
	public:
		void setSDLEvent(SDL_Event* n) { m_ev = n; }
		void setPressed(bool flag) { m_pressed = flag; }
		std::string getText() const { return m_text; }
		bool isPressed() const { return m_pressed; }
		bool isHovered() const { return m_hovered; }
	};
}
}
