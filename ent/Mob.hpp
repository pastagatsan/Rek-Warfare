#pragma once

#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace rekwarfare {
namespace client {

	enum Direction { LEFT, RIGHT };

	class Mob : public Entity {

	public:
		Mob(SDL_Rect box, SDL_Renderer* rend, int speed, int health);
	protected:
		int m_speed = 0;
		double m_health = 0;
		Direction m_direction = RIGHT;
		virtual void jump() { }
		virtual void climbDown() { }
		virtual void moveLeft() { m_box.x -= m_speed; }
		virtual void moveRight() { m_box.x += m_speed; }
	public:
		int getSpeed() { return m_speed; }
		double getHealth() { return m_health; }

	};
}
}
