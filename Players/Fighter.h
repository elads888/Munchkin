
#ifndef MUNCHKIN_FIGHTER_H
#define MUNCHKIN_FIGHTER_H
#include "Player.h"


class Fighter : public Player{
private:
public:
    Fighter(const std::string &name) : Player(name){};
    Fighter(const Fighter& other) = delete;
    Fighter& operator=(const Fighter& other) = delete;
    int getAttackStrength() const override;

protected:
    void printDetails(std::ostream& os) const override;

};


#endif //MUNCHKIN_FIGHTER_H
