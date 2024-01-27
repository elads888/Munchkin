#include "Gang.h"


//void Gang::bindGang(std::vector<std::unique_ptr<BattleCards>> &gang) {
//    for (std::unique_ptr<BattleCards> &card: gang) {
//        m_gang.push_back(std::move(card));
//    }
//}

void Gang::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}


void Gang::applyEncounter(Player &player) {
    bool lost = false;
    for (const std::unique_ptr<BattleCards> &card: m_gang) {
        if (card->getForce() <= player.getAttackStrength() && !lost) {
            player.addCoins(card->getLoot());
        } else {
            card->lose(player);
            lost = true;
        }
    }
    if (!lost) {
        player.levelUp();
        printWinBattle(player.getName(), "Gang");
    }
}

void Gang::addToGang(BattleCards *card) {
    m_gang.push_back(std::unique_ptr<BattleCards>(card));
}

std::string Gang::getName() const {
    return "Gang";
}
