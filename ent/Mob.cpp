#include "Mob.hpp"

namespace entity {
namespace mob { 

Mob::Mob(int id, SDL_Rect* box): Entity(box) { Mob::id = id; }
void Mob::render() { }
double Mob::getHP() { return Mob::hp; }
int Mob::getID() { return Mob::id; }

} 
}
