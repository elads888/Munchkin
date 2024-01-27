//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>

#include "../Players/Player.h"
#include "../utilities.h"

/*Abstract class*/
class Card {
protected:
    const std::string m_name;

    friend std::ostream &
    operator<<(std::ostream &os, const Card &card); /*friend method - can access Player private attributes*/
    virtual void printDetails(std::ostream &os) const = 0; /* pure virtual function*/

public:
    Card(const std::string &name) : m_name(name) {};

    virtual void applyEncounter(Player &player) = 0;
    virtual std::string getName() const = 0;


    Card(const Card &) = delete; /*can't copy a card*/
    virtual ~Card() = default;

    Card &operator=(const Card &other) = delete; /*can't assign to a card*/
};

#endif //EX2_Card_H
