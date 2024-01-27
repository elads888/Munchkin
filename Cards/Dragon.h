
#ifndef MUNCHKIN_DRAGON_H
#define MUNCHKIN_DRAGON_H

#include "BattleCards.h"

class Dragon : public BattleCards {
public:
    Dragon(int force = 25, int loot = 1000, int damage = Player::MAX_HP) : BattleCards("Dragon", force, loot,
                                                                                       damage) {};

    Dragon(const Dragon &dragon) = delete;

    Dragon &operator=(const Dragon &dragon) = delete;

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;

    void lose(Player &player) override;
};


#endif //MUNCHKIN_DRAGON_H
