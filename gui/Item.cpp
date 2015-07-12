#include "Item.hpp"
#include "../ent/Entity.hpp"
#include "SDL2/SDL.h"

namespace gui {
	Item::Item(SDL_Renderer* rend) : entity::Entity(rend, m_box) { }
}
