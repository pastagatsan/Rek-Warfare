#include "Tile.hpp"
#include "../ent/Entity.hpp"

namespace entity {
namespace map {

	Tile::Tile(SDL_Renderer* rend, ID id) : Entity(rend, m_box), m_id(id) { }
	Tile::Tile(SDL_Renderer* rend, ID id, Mask mask) : Entity(rend, m_box), m_id(id), m_mask(mask) { }

	void Tile::update() { }
	void Tile::render() const { }
}
}
