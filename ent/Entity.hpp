#pragma once

#include "SDL2/SDL.h"

namespace entity {

	/* Block identifications */
	const unsigned ID_AIR = 0;
	// Bricks ------------------------------------------
	const unsigned ID_STONE_BRICK = 1;
	const unsigned ID_RED_BRICK = 2;
	const unsigned ID_CRACKED_STONE_BRICK = 3;
	const unsigned ID_CRACKED_RED_BRICK = 4;
	// Water (requires animation, therefore 3 tiles) ---
	// B_WATER = Blue water
	// G_WATER = Green water
	// D_WATER = Dark water
	const unsigned ID_B_WATER_START = 5;
	const unsigned ID_B_WATER_MID = 6;
	const unsigned ID_B_WATER_END = 7;
	const unsigned ID_G_WATER_START = 8;
	const unsigned ID_G_WATER_MID = 9;
	const unsigned ID_G_WATER_END = 10;
	const unsigned ID_D_WATER_START = 11;
	const unsigned ID_D_WATER_MID = 12;
	const unsigned ID_D_WATER_END = 13;
	// Lava -------------------------------------------
	const unsigned ID_LAVA_START = 14;
	const unsigned ID_LAVA_MID = 15;
	// Bubble effect. When lava has bubbles... and pops...
	const unsigned ID_LAVA_MID_BUBBLESTART = 16;
	const unsigned ID_LAVA_MID_BUBBLEMID = 17;
	const unsigned ID_LAVA_MID_BUBBLEEND = 18;
	const unsigned ID_LAVA_END = 19;

	class Entity {

	public:
		Entity(SDL_Rect box);
		virtual ~Entity();
		virtual void render();
		void setID(int id) { m_id = id; }
		void setX(int x) { m_box.x = x; }
		void setY(int y) { m_box.y = y; }
		int getID() { return m_id; }
		int getX() { return m_box.x; }
		int getY() { return m_box.y; }

	protected:
		SDL_Rect m_box;
		int m_id;
	};
}
