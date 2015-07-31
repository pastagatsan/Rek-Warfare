#include "Item.hpp"
#include "../ent/Entity.hpp"
#include "SDL2/SDL.h"

namespace rekwarfare {
namespace client {
	Item::Item(SDL_Renderer* rend) : Entity(rend, m_box) { }
}
}
