#include "Player.hpp"
#include "Entity.hpp"
#include "Mob.hpp"
#include "SDL2/SDL.h"

#include <string>

namespace entity {
namespace mob {

	std::string classNameToStr(Class cn) {
		switch (cn) {
			case RAIDER:
				return "RAIDER";
				break;
			case MARINER:
				return "MARINER";
				break;
			case SORCERER:
				return "SORCERER";
				break;
			case TECH_MASTER:
				return "TECH MASTER";
				break;
			case BIO_PRO:
				return "BIO PRO";
				break;
		}
		return NULL;
	}

	Player::Player(Class c, std::string username)
		: Mob(m_box, m_speed, m_health), m_class(c), m_username(username) {
		switch (c) {
			case RAIDER:
				m_health = DEFAULT_RAIDER_FULL_HEALTH;
				break;
			case MARINER:
				m_health = DEFAULT_MARINER_FULL_HEALTH;
				break;
			case SORCERER:
				m_health = DEFAULT_SORCERER_FULL_HEALTH;
				break;
			case TECH_MASTER:
				m_health = DEFAULT_TECHMASTER_FULL_HEALTH;
				break;
			case BIO_PRO:
				m_health = DEFAULT_BIOPRO_FULL_HEALTH;
				break;
		}
	}

	std::string getUsername() {
		return m_username;
	}

	void Player::update() { }

	void Player::input() {
		const Uint8* key = SDL_GetKeyboardState(nullptr);
		if (key[SDL_SCANCODE_W]) {
			// Shouldn't be messed with until ladders come about
		} else if (key[SDL_SCANCODE_S]) {

		}
		if (key[SDL_SCANCODE_A]) {

		} else if (key[SDL_SCANCODE_D]) {
			// Shouldn't be messed with until ladders come about
		} else if (key[SDL_SCANCODE_SPACE]) {
			// Implement jumping when physics are available
		}
	}
	void Player::render(SDL_Renderer* rend) const {

	}
}
}
