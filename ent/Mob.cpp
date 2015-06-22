#include "Mob.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace mob {

Mob::Mob(int id, SDL_Rect box, int speed, int health): Entity(box) {
	Mob::m_id = id;
	Mob::m_speed = speed;
	Mob::m_hp = health;
}

Mob::~Mob() { }
void Mob::render() { }

}
}
