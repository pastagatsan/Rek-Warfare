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
	};
}	
}

#endif