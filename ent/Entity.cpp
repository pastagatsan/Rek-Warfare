#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {

Entity::Entity(SDL_Renderer* rend, SDL_Rect box) : m_box(box), m_rend(rend) { }

}
