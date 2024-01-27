#include "Dragon.h"

void Dragon::applyEncounter(Player &player) {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Dragon");
    } else {
        lose(player);
    }
}


void Dragon::lose(Player &player) {
    player.damage(m_damage);
    printLossBattle(player.getName(), "Dragon");
}

void Dragon::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_damage, m_loot, true);
    printEndOfCardDetails(os);
}

std::string Dragon::getName() const {
    return "Dragon";
}
