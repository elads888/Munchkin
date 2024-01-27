#include "Fairy.h"

void Fairy::applyEncounter(Player &player) {
    /*only wizards get healed from a fairy card*/
    Wizard *wizard = dynamic_cast<Wizard *>(&player);
    if (wizard != nullptr) {
        wizard->heal(HEAL);
        printFairyMessage(true);
    } else {
        printFairyMessage(false);
    }
}

void Fairy::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

std::string Fairy::getName() const {
    return "Fairy";
}
