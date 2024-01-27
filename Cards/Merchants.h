#ifndef MUNCHKIN_MERCHANTS_H
#define MUNCHKIN_MERCHANTS_H

struct healthPotion {
    int price;
    int boost;

    healthPotion() : price(5), boost(1) {};
};

struct forceBoost {
    int price;
    int boost;

    forceBoost() : price(10), boost(1) {};
};

#endif //MUNCHKIN_MERCHANTS_H
