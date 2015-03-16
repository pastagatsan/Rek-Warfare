#include "Mob.hpp"

namespace entity {
namespace mob { 

Character::Character(int id, SDL_Rect* box): Entity(box) { }

void Character::input() { }
void Character::render() { }
double Character::getHP() { return Character::hp; }
int Character::getID() { return Character::id; }

} 
}
