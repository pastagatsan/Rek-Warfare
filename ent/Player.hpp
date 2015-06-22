#pragma once

#include "Entity.hpp"
#include "Mob.hpp"

#include <string>

namespace entity {
namespace mob {

	enum Class { RAIDER, MARINER, SORCERER, TECH_MASTER, BIO_PRO };
	std::string className(Class cn);

	class Player : public Mob {

	public:
		Player(Class c, std::string username);
		void input();
		void render() override;

	private:
		SDL_Rect m_box;
		std::string m_username;
		Class m_class;
		int m_health;
		int m_x, m_y;
		int m_id;
	};
}
}
