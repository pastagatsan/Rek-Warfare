#include "Tile.hpp"
#include "../ent/Entity.hpp"

namespace rekwarfare {
namespace client {

	Tile::Tile(SDL_Renderer* rend, ID id) : Entity(rend, m_box), m_id(id) { }

	void Tile::update() {

		mi_tick++;
	}

	void Tile::render() const {

	}
}
}
