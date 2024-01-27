

#ifndef MUNCHKIN_GOBLIN_H
#define MUNCHKIN_GOBLIN_H

#include "BattleCards.h"


class Goblin : public BattleCards {
public:
    Goblin(int force = 6, int loot = 2, int damage = 10) : BattleCards("Goblin", force, loot, damage) {};

    Goblin(const Goblin &goblin) = delete;

    Goblin &operator=(const Goblin &goblin) = delete;

    void applyEncounter(Player &player) override;

    std::string getName() const override;

    void lose(Player &player) override;
};


#endif //MUNCHKIN_GOBLIN_H
