#ifndef MUNCHKIN_GANG_H
#define MUNCHKIN_GANG_H

#include <vector>
#include <memory>


#include "Card.h"
#include "BattleCards.h"


class Gang : public BattleCards {
private:
    std::vector<std::unique_ptr<BattleCards>> m_gang;
public:
    Gang() : BattleCards("Gang", 0, 0, 0), m_gang() {};

    void applyEncounter(Player &player) override;

    void printDetails(std::ostream &os) const override;

    std::string getName() const override;

    void addToGang(BattleCards* card);
};


#endif //MUNCHKIN_GANG_H
