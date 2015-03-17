#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../graphics/Drawer.hpp"

namespace entity {
	
Entity::Entity(SDL_Rect* box) : rect(box) { }
void Entity::render() { }

}
