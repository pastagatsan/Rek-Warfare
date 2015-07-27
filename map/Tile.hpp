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

	class Tile : public Entity {

	public:
		Tile(SDL_Renderer* rend, ID id);
		void update() override;
		void render() const override;
	private:
		ID m_id = AIR;
	};
}
}
