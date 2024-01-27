#include "BattleCards.h"

void BattleCards::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_damage, m_loot, false);
    printEndOfCardDetails(os);
}

int BattleCards::getLoot() const {
    return m_loot;
}

int BattleCards::getForce() const {
    return m_force;
}

void BattleCards::lose(Player &player) {
    printLossBattle(player.getName(), m_name);
}

std::string BattleCards::getName() const {
    return m_name;
}

