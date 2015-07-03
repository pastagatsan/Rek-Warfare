#include "Tile.hpp"
#include "../ent/Entity.hpp"

namespace entity {
namespace map {

	Tile::Tile(ID id) : Entity(m_box), m_id(id) { }
	Tile::Tile(ID id, Mask mask) : Entity(m_box), m_id(id), m_mask(mask) { }

	void Tile::update() { }
	void Tile::render(SDL_Renderer* rend) const { }
}
}
