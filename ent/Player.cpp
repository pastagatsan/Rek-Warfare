#include "Player.hpp"
#include "Entity.hpp"
#include "Mob.hpp"
#include <string>

namespace entity {
namespace mob {

    std::string className(Class cn) {
        switch (cn) {
            case RAIDER:
                return "RAIDER";
                break;
            case MARINER:
                return "MARINER";
                break;
            case SORCERER:
                return "SORCERER";
                break;
            case TECH_MASTER:
                return "TECH MASTER";
                break;
            case BIO_PRO:
                return "BIO PRO";
                break;
        }
        return null;
    }

    Player::Player(Class c, std::string username) : Mob(Player::id, Player::p_speed, Player::p_health) { 
        Player::p_class = c;
        Player::p_username = username;
    }
}
}
