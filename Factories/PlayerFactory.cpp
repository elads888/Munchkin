#include "PlayerFactory.h"

Player *PlayerFactory::CreatePlayer(const std::string &type, const std::string &name) {
    Player* player = this->FactoryMethod(type, name);
    return player;
}

Player *PlayerFactory::FactoryMethod(const std::string &type, const std::string &name) {
    if (type == "Wizard")
        return new Wizard(name);
    else if (type == "Fighter")
        return new Fighter(name);
    else
        return new Rogue(name);
}

