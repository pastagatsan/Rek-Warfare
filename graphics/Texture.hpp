#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <string>

namespace drawer {

	/**
	* Information of a custom tile
	*/
	typedef struct {
		int tw;
		int th;
		int xoff;
		int yoff;
	} SpriteTile;

	// Use if you do not want to use a section of a texture
	const SpriteTile FULL_IMAGE = {-1, -1, -1, -1};

	typedef struct {
		int w;
		int h;
		std::string path;
	} TextureInfo;

	class Texture {

	public:
		Texture(SDL_Texture* tex, SDL_Renderer* rend);
		~Texture();
		/**
		 * Draws the texture. You decide wether to draw a section or all of it
		 * @tw - width of section to crop
		 * @th - height of section to crop
		 * @xoff - x offset
		 * @yoff - y offset
		 * @x - x coordinate
		 * @y - y coordinate
		 * @w - width
		 * @h - height
		 */
		void draw(SpriteTile tile, int x, int y, int w, int h);
		/**
		 * Sets the texture's color, set to NULL for uncolored texture
		 */
		void setColor(Uint8 r, Uint8 g, Uint8 b);
		SDL_Texture* getTexture();

	private:
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		SDL_Color m_color;
		TextureInfo m_texinf;
		std::string m_path;

	};
}
