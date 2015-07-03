#pragma once

#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace mob {

	enum Direction { UP, DOWN, LEFT, RIGHT };

	class Mob : public Entity {

	public:
		Mob(int id, SDL_Rect box, int speed, int health);
		void move(Direction dir, int speed);
		// Move with m_speed
		void move(Direction dir);
		int getSpeed() { return m_speed; }
		double getHealth() { return m_health; }
	protected:
		int m_speed = 0;
		double m_health = 0;
	};
}
}
