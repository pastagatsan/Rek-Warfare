#include "Mob.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace mob {

Mob::Mob(SDL_Rect box, SDL_Renderer* rend, int speed, int health)
	: Entity(rend, box), m_speed(speed), m_health(health) { }

}
}
