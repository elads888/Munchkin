#ifndef MUNCHKIN_WIZARD_H
#define MUNCHKIN_WIZARD_H
#include "Player.h"


class Wizard : public Player{
public:
    Wizard(const std::string &name) : Player(name){};
    Wizard(const Wizard& other) = delete;
    Wizard& operator = (const Wizard& other) = delete;
    void heal(int HPToAdd) override;

protected:
    void printDetails(std::ostream& os) const override;
};


#endif //MUNCHKIN_WIZARD_H
