#include "Item.hpp"
#include "../ent/Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace gui {
	Item::Item(SDL_Renderer* rend) : Entity(rend, m_box) { }

	Item::~Item() { }
}
}
