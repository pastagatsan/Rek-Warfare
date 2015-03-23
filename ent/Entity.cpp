#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../graphics/Drawer.hpp"

namespace entity {

Entity::Entity(SDL_Rect* box) : rect(box) { }
void Entity::render() { }

void Entity::setX(int x) {
	Entity::box->x = x;
}

void Entity::setY(int y) {
	Entity::box->y = y;
}

int Entity::getX() {
	return Entity::box->x;
}

int Entity::getY() {
	return Entity::box->y;
}

}
