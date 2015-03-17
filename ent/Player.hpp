#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Mob.hpp"
#include <string>

namespace entity {
namespace mob { 
	
	enum Class { RADIER, MARINER, SORCERER, TECH_MASTER, BIO_PRO };
	
	class Player : public Mob { 
		
	public:
		Player(Class c, std::string username);
	};
}	
}

#endif