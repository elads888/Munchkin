#include "Vampire.h"

void Vampire::applyEncounter(Player &player) {

    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Vampire");
    } else {
        lose(player);
    }
}


void Vampire::lose(Player &player) {
    player.damage(m_damage);
    player.buff(FORCE_TO_WEAKEN);
    printLossBattle(player.getName(), "Vampire");
}

std::string Vampire::getName() const {
    return "Vampire";
}
