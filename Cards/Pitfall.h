#ifndef MUNCHKIN_PITFALL_H
#define MUNCHKIN_PITFALL_H

#include "Card.h"
#include "../Players/Rogue.h"

class Pitfall : public Card {
private:
    static const int DAMAGE = 10;
public:
    Pitfall() : Card("Pitfall") {};

    Pitfall(const Pitfall &pitfall) = delete;

    Pitfall &operator=(const Pitfall &pitfall) = delete;

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;
};


#endif //MUNCHKIN_PITFALL_H
