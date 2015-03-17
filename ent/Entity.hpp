#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SDL2/SDL.h"

namespace entity { 
    
    class Entity { 
	
    public:
		Entity(SDL_Rect* box);
		virtual void render();
	protected:
		SDL_Rect* rect;
    };
}

#endif