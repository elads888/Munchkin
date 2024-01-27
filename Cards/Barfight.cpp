#include "Barfight.h"

void Barfight::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Barfight::applyEncounter(Player &player) {
    /*Barfight only damage players that are not fighters*/
    Fighter *fighter = dynamic_cast<Fighter *>(&player);
    if (fighter == nullptr) {
        player.damage(DAMAGE);
        printBarfightMessage(false);
    } else {
        printBarfightMessage(true);
    }
}

std::string Barfight::getName() const {
    return "Barfight";
}

