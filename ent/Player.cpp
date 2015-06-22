#include "Player.hpp"
#include "Entity.hpp"
#include "Mob.hpp"

#include <string>

namespace entity {
namespace mob {

	std::string className(Class cn) {
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

	void Player::input() { }
	void Player::render() { }
}
}
