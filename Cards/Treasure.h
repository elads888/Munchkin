#ifndef MUNCHKIN_TREASURE_H
#define MUNCHKIN_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    static const int LOOT = 10;

    Treasure() : Card("Treasure") {};

    Treasure(const Treasure &treasure) = delete;

    Treasure &operator=(const Treasure &treasure) = delete;

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;

};
#endif //MUNCHKIN_TREASURE_H
