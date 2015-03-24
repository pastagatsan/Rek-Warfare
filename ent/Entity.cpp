#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "graphics/Drawer.hpp"

namespace entity {

Entity::Entity(SDL_Rect* box) : e_box(box) { }

void Entity::render() { }

void Entity::setX(int x) {
	Entity::e_box->x = x;
}

void Entity::setY(int y) {
	Entity::e_box->y = y;
}

int Entity::getX() {
	return Entity::e_box->x;
}

int Entity::getY() {
	return Entity::e_box->y;
}

}
