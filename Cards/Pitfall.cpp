#include "Pitfall.h"

void Pitfall::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Pitfall::applyEncounter(Player &player) {
    /*only rogues don't get damage from a pitfall card*/
    Rogue *rogue = dynamic_cast<Rogue *>(&player);
    if (rogue == nullptr) {
        player.damage(DAMAGE);
        printPitfallMessage(false);
    } else {
        printPitfallMessage(true);
    }
}

std::string Pitfall::getName() const {
    return "Pitfall";
}
