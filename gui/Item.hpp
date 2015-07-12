#pragma once

#include "../ent/Entity.hpp"
#include "SDL2/SDL.h"

namespace gui {

	class Item : public entity::Entity {

	public:
		Item(SDL_Renderer* rend);
		void update() override;
		void render() const override;
	private:
	};
}
