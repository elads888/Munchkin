#include "Goblin.h"

void Goblin::applyEncounter(Player &player) {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), "Goblin");
    } else {
        lose(player);
    }
}

void Goblin::lose(Player &player) {
    player.damage(m_damage);
    printLossBattle(player.getName(), "Goblin");
}

std::string Goblin::getName() const {
    return "Goblin";
}
