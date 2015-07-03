#include "Mob.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace mob {

Mob::Mob(SDL_Rect box, int speed, int health)
	: Entity(box), m_speed(speed), m_health(health) { }

}
}
