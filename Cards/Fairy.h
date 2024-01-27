#ifndef MUNCHKIN_FAIRY_H
#define MUNCHKIN_FAIRY_H

#include "Card.h"
#include "../Players/Wizard.h"

class Fairy : public Card {
private:
    static const int HEAL = 10;
public:
    Fairy() : Card("Fairy") {};

    Fairy(const Fairy &fairy) = delete;

    Fairy &operator=(const Fairy &fairy) = delete;

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;
};

#endif //MUNCHKIN_FAIRY_H
