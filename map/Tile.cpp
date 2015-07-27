#include "Tile.hpp"
#include "../ent/Entity.hpp"

namespace entity {
namespace map {

	Tile::Tile(SDL_Renderer* rend, ID id) : Entity(rend, m_box), m_id(id) { }

	void Tile::update() { }
	void Tile::render() const { }
}
}
