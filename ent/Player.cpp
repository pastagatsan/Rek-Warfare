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
		: Mob(m_id, m_box, m_speed, m_health), m_class(c), m_username(username) { }

	void Player::update() { }

	void Player::input() {
		const Uint8* key = SDL_GetKeyboardState(nullptr);
		if (key[SDL_SCANCODE_W]) {
			// TODO: Decide weather SPACE or W wi		return ll be the default jump key
		} else if (key[SDL_SCANCODE_S]) {

		}
		if (key[SDL_SCANCODE_A]) {

		} else if (key[SDL_SCANCODE_D]) {
			// Shouldn't be messed with until ladders come about
		}
	}
	void Player::render(SDL_Renderer* rend) const { }
}
}
