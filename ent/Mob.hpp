#ifndef MOB_HPP
#define MOB_HPP

#include "Entity.hpp"

namespace entity {
	namespace mob { 
		
		
		class Mob : public Entity {
			
		public:
			Mob(int id, SDL_Rect* box);
			void render() override;
			int getID();
			int getSpeed();
			double getHP();
			
		protected:
			double hp;
			int id;
			int speed;
		};
	}
}

#endif