#pragma once

#include "../ent/Entity.hpp"

namespace entity {
namespace map {

	enum ID {
		AIR,
		RED_BRICK,
		STONE_BRICK,
		LAVA,
		WATER_CLEAR,
		WATER_POLLUTED,
		SUPPORT_BEAM_METAL_NEW,
		SUPPORT_BEAM_METAL_RUST,
		SUPPORT_BEAM_CONCRETE_NEW,
		SUPPORT_BEAM_CONCRETE_CRACKED,
	};

	enum Mask {
		GRAFFITI_GAME_LOGO,
		GRAFFITI_LENNY,
		GRAFFITI_RAIDER_SKETCH,
		BRICK_CRACK
	};

	class Tile : public Entity {

	public:
		Tile(ID id);
		Tile(ID, Mask mask);
		void update() override;
		void render(SDL_Renderer* rend) const override;
	private:
		ID m_id = AIR;
		Mask m_mask;
	};
}
}
