#include "Merchant.h"


bool Merchant::validChoice(int choice) {
    for (int valid = validChoices::nothing; valid <= validChoices::forceBoost; valid++) {
        if (choice == valid) {
            return true;
        }
    }
    printInvalidInput();
    return false;
}

void Merchant::applyEncounter(Player &player) {
    std::string choice;
    int c = -1;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    do {
        getline(std::cin, choice);
        try {
            c = std::stoi(choice);
        }
        catch (const std::exception &e) {
            c = -1;
        }
    } while (!validChoice(c));
    if (c == validChoices::nothing) {
        printMerchantSummary(std::cout, player.getName(), c, 0);
        return;
    } else if (c == validChoices::healthPotion) {
        if (player.pay(m_healthPotion.price)) {
            player.heal(m_healthPotion.boost);
            printMerchantSummary(std::cout, player.getName(), c, m_healthPotion.price);
            return;
        } else {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getName(), c, 0);
        }
    } else if (c == validChoices::forceBoost) {
        if (player.pay(m_forceBoost.price)) {
            player.buff(m_forceBoost.boost);
            printMerchantSummary(std::cout, player.getName(), c, m_forceBoost.price);
            return;
        } else {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getName(), c, 0);
        }
    }
}

void Merchant::printDetails(std::ostream &os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

std::string Merchant::getName() const {
    return "Merchant";
}
