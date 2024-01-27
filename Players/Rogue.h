
#ifndef MUNCHKIN_ROGUE_H
#define MUNCHKIN_ROGUE_H

#include "Player.h"
class Rogue : public Player{
public:
    Rogue(const std::string &name): Player(name){};
    Rogue(const Rogue &other) = delete;
    Rogue& operator =(const Rogue &other) = delete;
    void addCoins(int coinsToAdd) override;
protected:
    void printDetails(std::ostream& os) const override;
};

#endif //MUNCHKIN_ROGUE_H
