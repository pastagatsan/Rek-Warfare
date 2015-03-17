#ifndef MOB_HPP
#define MOB_HPP

#include "Entity.hpp"

namespace entity {
	namespace mob { 
		
		
		class Mob : public Entity {
			
		public:
			Mob(int id, SDL_Rect* box);
			friend void input();
			friend void render();
			int getID();
			double getHP();
			
		protected:
			double hp;
			int id;
		};
	}
}

#endif