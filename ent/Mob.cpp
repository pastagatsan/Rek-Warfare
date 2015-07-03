#include "Mob.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace mob {

Mob::Mob(int id, SDL_Rect box, int speed, int health): Entity(box, id) {
	Mob::m_id = id;
	Mob::m_speed = speed;
	Mob::m_health = health;
}

void Mob::move(Direction dir, int speed) {
	switch (dir) {
		case UP:
			m_box.y -= speed;
			break;
		case DOWN:
			m_box.y += speed;
			break;
		case LEFT:
			m_box.x -= speed;
			break;
		case RIGHT:
			m_box.y += speed;
			break;
	}
}

void Mob::move(Direction dir) {
	move(dir, m_speed);
}

}
}
