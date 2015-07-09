#pragma once

#include "Entity.hpp"
#include "Mob.hpp"

#include <string>

namespace entity {
namespace mob {

	const unsigned int DEFAULT_RAIDER_FULL_HEALTH = 200;
	const unsigned int DEFAULT_BIOPRO_FULL_HEALTH = 155;
	const unsigned int DEFAULT_MARINER_FULL_HEALTH = 135;
	const unsigned int DEFAULT_SORCERER_FULL_HEALTH = 180;
	const unsigned int DEFAULT_TECHMASTER_FULL_HEALTH = 155;

	enum Class { RAIDER, MARINER, SORCERER, TECH_MASTER, BIO_PRO };
	std::string classNameToStr(Class cn);

	class Player : public Mob {

	public:
		Player(SDL_Renderer* rend, Class c, std::string username);
		void update() override;
		void input();
		void render() const override;
	private:
		std::string m_username;
		Class m_class;
		SDL_Texture* m_inittex = nullptr;
	public:
		std::string getUsername();
		Class getClass() { return m_class; }

	};
}
}
