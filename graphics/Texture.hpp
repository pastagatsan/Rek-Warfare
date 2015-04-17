#pragma once
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace drawer { 

	class Texture { 
	
	public:
		Texture(std::string path);
		void draw(int x, int y, int w, int h);
		void drawSprite(int xoff, int yoff, int x, int y, int w, int h);
		SDL_Texture* getTexture();
		
	private:
		SDL_Texture* texture;
		std::string tpath;
		
	};
}
