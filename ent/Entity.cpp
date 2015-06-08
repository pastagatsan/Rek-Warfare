#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {

Entity::Entity(SDL_Rect box) : m_box(box) { }

Entity::~Entity() { }

void Entity::render() { }

}
