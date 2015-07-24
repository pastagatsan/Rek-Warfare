#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {

Entity::Entity(SDL_Renderer* rend, SDL_Rect box) : m_box(box), m_rend(rend) { }

void Entity::setSize(int w, int h) {
	m_box.w = w;
	m_box.h = h;
}

void Entity::setCoordinates(int x, int y) {
	m_box.x = x;
	m_box.y = y;
}
}
