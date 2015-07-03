#include "Tile.hpp"
#include "../ent/Entity.hpp"

namespace entity {
namespace map {

	Tile::Tile(ID id) : m_id(id) { }
	Tile::Tile(ID id, Mask mask) : m_id(id), m_mask(mask) { }
}
}
