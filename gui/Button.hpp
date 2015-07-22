#pragma once

#include "../ent/Entity.hpp"
#include "Item.hpp"
#include "SDL2/SDL.h"

#include <string>

namespace entity {
namespace gui {

	class Button : public Item {

	public:
		Button(SDL_Renderer* rend, std::string text);
		~Button();
		virtual void update() override;
		virtual void render() const override;
	private:
		SDL_Texture* m_unpushed, m_pushed;
	protected:
		bool m_pressed = false;
		std::string m_text = "Button";
	public:
		void setPressed(bool flag) { m_pressed = flag; }
		std::string getText() const { return m_text; }
		bool isPressed() const { return m_pressed; }
	};
}
}
