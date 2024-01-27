#ifndef MUNCHKIN_MERCHANTCARDS_H
#define MUNCHKIN_MERCHANTCARDS_H

#include <iostream>
#include <string>
#include <sstream>

#include "Card.h"
#include "Merchants.h"
#include "../utilities.h"
#include "../Exception.h"


class Merchant : public Card {
private:
    bool validChoice(int choice);

    enum validChoices {
        nothing = 0, healthPotion = 1, forceBoost = 2
    };

    struct forceBoost m_forceBoost;
    struct healthPotion m_healthPotion;

public:
    Merchant() : Card("Merchant"), m_forceBoost(), m_healthPotion() {};

    Merchant(const Merchant &merchant) = delete;

    Merchant &operator=(const Merchant &merchant) = delete;

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;

};


#endif //MUNCHKIN_MERCHANTCARDS_H
