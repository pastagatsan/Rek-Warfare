#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {

Entity::Entity(SDL_Rect box) : m_box(box) { }
Entity::Entity(SDL_Rect box, int id) : m_box(box), m_id(id) { }

Entity::~Entity() { }
void Entity::update() { }
void Entity::render(SDL_Renderer* rend) const { }

}
