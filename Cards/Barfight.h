#ifndef MUNCHKIN_BARFIGHT_H
#define MUNCHKIN_BARFIGHT_H

#include "Card.h"
#include "../Players/Fighter.h"


class Barfight : public Card {
private:
    static const int DAMAGE = 10;
public:
    Barfight() : Card("Barfight") {}; /* initialization list + inheritance*/
    Barfight(const Barfight &barfight) = delete;

    Barfight &operator=(const Barfight &barfight) = delete;

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;
};


#endif //MUNCHKIN_BARFIGHT_H
