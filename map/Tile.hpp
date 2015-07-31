#pragma once

#include "../ent/Entity.hpp"

namespace rekwarfare {
namespace client {

	typedef unsigned char ID;

	const ID AIR = 0;
	const ID RED_BRICK = 1;
	const ID STONE_BRICK = 2;
	const ID LAVA = 3;
	const ID WATER_CLEAR = 4;
	const ID WATER_POLLUTED = 5;
	const ID SUPPORT_BEAM_METAL_NEW = 6;
	const ID SUPPORT_BEAM_METAL_RUST = 7;
	const ID SUPPORT_BEAM_CONCRETE_NEW = 8;
	const ID SUPPORT_BEAM_CONCRETE_CRACKED = 9;
	const ID WATER_TOP_CLEAR = 10;
	const ID WATER_TOP_POLLUTED = 11;
	const ID LAVA_TOP = 12;

	class Tile : public Entity {

	public:
		Tile(SDL_Renderer* rend, ID id);
		void update() override;
		void render() const override;
	private:
		ID m_id = AIR;
		int mi_tick = 0;
	};
}
}
