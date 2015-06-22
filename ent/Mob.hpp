#pragma once

#include "Entity.hpp"
#include "SDL2/SDL.h"

namespace entity {
namespace mob {

	class Mob : public Entity {

	public:
		Mob(int id, SDL_Rect box, int speed, int health);
		virtual ~Mob();
		virtual void render() override;
		int getSpeed() { return m_speed; }
		double getHP() { return m_hp; }
	protected:
		int m_speed;
		double m_hp;
		SDL_Rect m_box;
	};
}
}
