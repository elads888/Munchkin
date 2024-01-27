#ifndef MUNCHKIN_BATTLECARDS_H
#define MUNCHKIN_BATTLECARDS_H

#include "Card.h"

/*Abstract class*/
class BattleCards : public Card {
protected:
    int m_force;
    int m_loot;
    int m_damage;
public:
    /*initialization list*/
    BattleCards(const std::string name, int force, int loot, int damage) : Card(name), m_force(force), m_loot(loot),
                                                                           m_damage(damage) {};

    virtual void printDetails(std::ostream &os) const override;

    virtual std::string getName() const override;

    virtual int getForce() const;

    virtual int getLoot() const;

    virtual void lose(Player &player);
};

#endif //MUNCHKIN_BATTLECARDS_H
