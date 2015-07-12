/* The container for Items */
#pragma once

#include "../ent/Entity.hpp"

#include <vector>

namespace gui {

	class Panel : public entity::Entity {

	public:
		Panel(SDL_Renderer* rend, int x, int y, int w, int h);
		~Panel() override;
		void update() override;
		void render() const override;
	private:
		std::vector<Item> m_items;
	public:
		// Protable?
		size_t itemCount() const { return m_items.size(); }

	};

}
