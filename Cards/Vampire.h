
#ifndef MUNCHKIN_VAMPIRE_H
#define MUNCHKIN_VAMPIRE_H

#include "BattleCards.h"

class Vampire : public BattleCards {
private:
    static const int FORCE_TO_WEAKEN = -1;

public:
    Vampire(int force = 10, int loot = 2, int damage = 10) : BattleCards("Vampire", force, loot, damage) {};

    Vampire(const Vampire &vampire) = delete;

    Vampire &operator=(const Vampire &vampire) = delete;

    void applyEncounter(Player &player) override;

    void lose(Player &player) override;

    std::string getName() const override;
};

#endif //MUNCHKIN_VAMPIRE_H
