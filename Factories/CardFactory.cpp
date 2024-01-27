#include "CardFactory.h"

Card *CardFactory::CreateCard(const std::string &type) {
    Card* card = this->FactoryMethod(type);
    return card;
}

Card *CardFactory::FactoryMethod(const std::string &type) {
    if (type == "Barfight") {
        return new Barfight();
    } else if (type == "Pitfall") {
        return new Pitfall();
    } else if (type == "Fairy") {
        return new Fairy();
    } else if (type == "Dragon") {
        return new Dragon();
    }else if (type == "Gang") {
        return new Gang();
    }else if (type == "Goblin"){
        return new Goblin();
    }else if (type == "Merchant") {
        return new Merchant();
    } else if (type == "Treasure") {
        return new Treasure();
    } else {
        return new Vampire();
    }
}
