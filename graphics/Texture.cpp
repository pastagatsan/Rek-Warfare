#include "Texture.hpp"
#include "Drawer.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace drawer {

Texture::Texture(SDL_Texture* tex, SDL_Renderer* rend) {
	m_renderer = rend;
	m_texture = tex;

	// TODO: Place texture information in m_texinf
}

Texture::~Texture() {
	SDL_DestroyTexture(m_texture);
}

void Texture::draw(SpriteTile tile, int x, int y, int w, int h) {
	SDL_Rect* sec, *size;

	if (tile.xoff == FULL_IMAGE.xoff && // Possibly OR them?
		tile.yoff == FULL_IMAGE.yoff &&
		tile.tw == FULL_IMAGE.tw &&
		tile.th == FULL_IMAGE.th) {
		sec = nullptr;
	} else {
		sec->w = tile.tw;
		sec->h = tile.th;
		sec->x = tile.xoff * sec->w;
		sec->y = tile.yoff * sec->h;
	}

	size->x = x;
	size->y = y;
	size->w = w;
	size->h = h;

	drawTexture(m_renderer, m_texture, sec, size);
}

void Texture::setColor(Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetTextureColorMod(m_texture, r, g, b);
}

SDL_Texture* Texture::getTexture() {
	return m_texture;
}

}
