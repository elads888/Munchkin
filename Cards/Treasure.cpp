#include "Treasure.h"

void Treasure::applyEncounter(Player &player) {
    player.addCoins(10);
    printTreasureMessage();
}

void Treasure::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

std::string Treasure::getName() const {
    return "Treasure";
}
