#ifndef PLAYER_HPP
#define PLAYER_HPP

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
		std::string p_username;
		Class p_class;
		int p_x, p_y;
		int id;
	};
}
}

#endif
