#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SDL2/SDL.h"

namespace entity {

    class Entity {

    public:
		Entity(SDL_Rect* box);
		virtual void render();
        virtual void setX(int x);
        virtual void setY(int y);
        virtual int getX();
        virtual int getY();

	protected:
		SDL_Rect* e_box;
    };
}

#endif
