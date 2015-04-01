#pragma once

#include "Entity.hpp"

namespace entity {
	namespace mob {


		class Mob : public Entity {

		public:
			Mob(int id, SDL_Rect* box, int speed, int health);
			void render() override;
			int getID();
			int getSpeed();
			double getHP();

		protected:
			double p_hp;
			int p_speed;
			int p_id;
			SDL_Rect* p_box;
		};
	}
}
