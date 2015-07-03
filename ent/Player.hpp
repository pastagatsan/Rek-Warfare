#pragma once

#include "Entity.hpp"
#include "Mob.hpp"

#include <string>

namespace entity {
namespace mob {

	enum Class { RAIDER, MARINER, SORCERER, TECH_MASTER, BIO_PRO };
	std::string classNameToStr(Class cn);

	class Player : public Mob {

	public:
		Player(Class c, std::string username);
		void update() override;
		void input();
		void render(SDL_Renderer* rend) const override;
		Class getClass() { return m_class; }
	private:
		std::string m_username;
		Class m_class;
	};
}
}
